# float_to_fixed_point

Little program for the conversion of floating point numbers (float) to fixed point numbers (fix16_t) and backwards on the command line.

## Description:
This program return for a given number the representation in fix16_t or float

## Syntax:
`float_to_fixed_point [0x]NUMBER`

## Option:
`-h`, `--help`: displays this text

## `NUMBER`:
A number without a prefix and without a decimal point is interpreted as decimal representation of a fix16_t number. A number with a 0x prefix is interpreted as a hex representation of a fix16_t number. A number with a decimal point interpreted as a float number.
