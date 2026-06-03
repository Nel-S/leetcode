#ifndef LEETCODE_0065_CPP
#define LEETCODE_0065_CPP

// https://leetcode.com/problems/valid-number/submissions/2020954880

// Added by LeetCode in the background
#include <string>
using namespace std;

class Solution {
public:
    bool isNumber(string s) {
        /* From reading the instructions closely, this problem seems identical to
           recognizing the string [whitespace added for readability]
           [-+]? (?:[0-9]+(?:\.[0-9]*)? | \.[0-9]+) (?:[eE][-+]?[0-9]+)?
           Therefore we can simply design a DFA for this, then emulate it in code.
        */

        /* The possible states for our DFA. */
        enum State {
            START,
            INITIAL_SIGN, // [-+]?
            VALID_INTEGER_NO_EXPONENT, // [-+]?[0-9]+
            LEADING_DECIMAL_POINT, // [-+]?\.
            VALID_DECIMAL_NO_EXPONENT, // [-+]? (?:[0-9]+(?:\.[0-9]*)? | \.[0-9]+)
            EXPONENT_NOTATION, // ...[eE]
            EXPONENT_SIGN, // [eE][-+]?
            VALID_NUMBER_WITH_EXPONENT // [eE][-+]?[0-9]+
        };
        /* The accepting states for the DFA. */
        constexpr int ACCEPTING_STATES_BITMAP =
            (1 << VALID_INTEGER_NO_EXPONENT) |
            (1 << VALID_DECIMAL_NO_EXPONENT) |
            (1 << VALID_NUMBER_WITH_EXPONENT);

        /* Obviously we start at the START state. */
        int state = State::START;
        /* For each new character, branch based on the current state: */
        for (const char &character : s) {
            switch (state) {
                case State::START:
                    /* Seeing + or - gives us an initial sign */
                    if (character == '+' || character == '-') {
                        state = State::INITIAL_SIGN;
                        continue;
                    }
                    /* The remaining possible movements are identical to INITIAL_SIGN */
                    [[fallthrough]];
                case State::INITIAL_SIGN:
                    /* Any digit gives us a valid integer */
                    if (std::isdigit(character)) {
                        state = State::VALID_INTEGER_NO_EXPONENT;
                        continue;
                    }
                    /* . gives us the beginnings of a decimal (though currently still invalid) */
                    if (character == '.') {
                        state = State::LEADING_DECIMAL_POINT;
                        continue;
                    }
                    /* Any other character creates an invalid number */
                    return false;

                case State::VALID_INTEGER_NO_EXPONENT:
                    /* Any digit continues the valid integer */
                    if (std::isdigit(character)) {
                        continue;
                    }
                    /* . gives us a valid decimal */
                    if (character == '.') {
                        state = State::VALID_DECIMAL_NO_EXPONENT;
                        continue;
                    }
                    /* e or E give us the beginnings of an exponent (though currently invalid) */
                    if (character == 'e' || character == 'E') {
                        state = State::EXPONENT_NOTATION;
                        continue;
                    }
                    /* Any other character creates an invalid number */
                    return false;

                case State::LEADING_DECIMAL_POINT:
                    /* Any digit gives us a valid decimal */
                    if (std::isdigit(character)) {
                        state = State::VALID_DECIMAL_NO_EXPONENT;
                        continue;
                    }
                    /* Any other character creates an invalid number */
                    return false;

                case State::VALID_DECIMAL_NO_EXPONENT:
                    /* Any digit continues the valid decimal */
                    if (std::isdigit(character)) {
                        continue;
                    }
                    /* e or E give us the beginnings of an exponent (though currently invalid) */
                    if (character == 'e' || character == 'E') {
                        state = State::EXPONENT_NOTATION;
                        continue;
                    }
                    /* Any other character creates an invalid number */
                    return false;

                case State::EXPONENT_NOTATION:
                    /* Seeing + or - gives us a sign for the exponent */
                    if (character == '+' || character == '-') {
                        state = State::EXPONENT_SIGN;
                        continue;
                    }
                    /* The remaining possible movements are identical to EXPONENT_SIGN */
                    [[fallthrough]];
                case State::EXPONENT_SIGN:
                    /* Any digit gives us a valid exponent */
                    if (std::isdigit(character)) {
                        state = State::VALID_NUMBER_WITH_EXPONENT;
                        continue;
                    }
                    /* Any other character creates an invalid number */
                    return false;

                case State::VALID_NUMBER_WITH_EXPONENT:
                    /* Any digit continues the valid exponent */
                    if (std::isdigit(character)) {
                        continue;
                    }
                    /* Any other character creates an invalid number */
                    return false;
            }
        }
        /* Return whether the DFA ended in an accepting state. */
        return static_cast<bool>((1 << state) & ACCEPTING_STATES_BITMAP);
    }

};

#endif