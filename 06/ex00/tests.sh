#!/bin/bash

# Run tests for CPP-06-ex00
# Usage: make && ./tests.sh

# Colors
red='\033[31;1m'
blue='\033[36;1m'
green='\033[32;1m'
yellow='\033[33;1m'
purple='\033[35;1m'
gray='\033[37;1m'
reset='\033[0m'

# Caminho para o executável do seu programa em C
PROGRAM="./ScalarConverter"

comp="make re && clear"

$comp
clear

echo
echo -e "${purple}---------------------------------------------------------------"
echo -e "************************ CONVERT TEST *************************"
echo -e "---------------------------------------------------------------"
echo -e "${purple}No argument test.."
echo -e "---------------------------------------------------------------${reset}"

# Test with no argument
echo -e "${blue}./ScalarConverter${reset}"
${PROGRAM}

echo -e "${purple}---------------------------------------------------------------"
echo -e "Invalid input tests..."
echo -e "---------------------------------------------------------------${reset}"

# Test with invalid inputs
echo -e "${blue}./ScalarConverter 🌊${reset}"
${PROGRAM} 🌊
echo -e "${blue}\n./ScalarConverter 🌊🌊${reset}"
${PROGRAM} 🌊🌊
echo -e "${blue}\n./ScalarConverter teste${reset}"
${PROGRAM} teste
echo -e "${blue}\n./ScalarConverter \"teste\"${reset}"
${PROGRAM} "teste"
echo -e "${blue}\n./ScalarConverter 'teste'${reset}"
${PROGRAM} 'teste'
echo -e "${blue}\n./ScalarConverter 0000r${reset}"
${PROGRAM} 0000r
echo -e "${blue}\n./ScalarConverter '\\n'${reset}"
${PROGRAM} "'\n'"
echo -e "${blue}\n./ScalarConverter '\\t'${reset}"
${PROGRAM} "'\t'"
echo -e "${blue}\n./ScalarConverter '\\r'${reset}"
${PROGRAM} "'\r'"
echo -e "${blue}\n./ScalarConverter '\\v'${reset}"
${PROGRAM} "'\v'"
echo -e "${blue}\n./ScalarConverter '\\b'${reset}"
${PROGRAM} "'\b'"
echo -e "${blue}\n./ScalarConverter '\\f'${reset}"
${PROGRAM} "'\f'"
echo -e "${blue}\n./ScalarConverter '\\a'${reset}"
${PROGRAM} "'\a'"
echo -e "${blue}\n./ScalarConverter '\\e'${reset}"
${PROGRAM} "'\e'"
echo -e "${blue}\n./ScalarConverter '\\0'${reset}"
${PROGRAM} "'\0'"
echo -e "${blue}\n./ScalarConverter '\\x0'${reset}"
${PROGRAM} "'\x0'"
echo -e "${blue}\n./ScalarConverter '\\x0f'${reset}"
${PROGRAM} "'\x0f'"
echo -e "${blue}\n./ScalarConverter ' '${reset}"
${PROGRAM} "' '"
echo -e "${blue}\n./ScalarConverter '	'${reset}"
${PROGRAM} "'	'"


echo -e "${purple}\n---------------------------------------------------------------"
echo -e "Limit tests..."
echo -e "---------------------------------------------------------------${reset}"

# Test with limits
echo -e "${blue}./ScalarConverter 2147483647${reset}"
${PROGRAM} 2147483647
echo -e "${blue}\n./ScalarConverter -2147483648${reset}"
${PROGRAM} -2147483648
echo -e "${blue}\n./ScalarConverter 2147483648${reset}"
${PROGRAM} 2147483648
echo -e "${blue}\n./ScalarConverter -2147483649${reset}"
${PROGRAM} -2147483649
echo -e "${blue}\n./ScalarConverter 340282346638528859811704183484516925440.0f${reset}"
${PROGRAM} 340282346638528859811704183484516925440.0f
echo -e "${blue}\n./ScalarConverter -340282346638528859811704183484516925440.0000000000000000f${reset}"
${PROGRAM} -340282346638528859811704183484516925440.0000000000000000f
echo -e "${blue}\n./ScalarConverter 340282346638528859811704183484516925455.9f${reset}"
${PROGRAM} 340282446638528859811704183484516925455.9f
echo -e "${blue}\n./ScalarConverter -340282446638528859811704183484516925499.9900000000000000f${reset}"
${PROGRAM} -340282446638528859811704183484516925499.9900000000000000f
echo -e "${blue}\n./ScalarConverter 179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.0${reset}"
${PROGRAM} 179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.0
echo -e "${blue}\n./ScalarConverter -179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.0${reset}"
${PROGRAM} -179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.0
echo -e "${blue}\n./ScalarConverter 179769313486239570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858399.9${reset}"
${PROGRAM} 179769313486239570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858399.9
echo -e "${blue}\n./ScalarConverter -179769313486239570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858399.9${reset}"
${PROGRAM} -179769313486239570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858399.9

echo -e "${purple}\n---------------------------------------------------------------"
echo -e "Char tests..."
echo -e "---------------------------------------------------------------${reset}"

# Test with char
echo -e "${blue}./ScalarConverter 'c'${reset}"
${PROGRAM} "c"
echo -e "${blue}\n./ScalarConverter 'a'${reset}"
${PROGRAM} "a"
echo -e "${blue}\n./ScalarConverter 'A'${reset}"
${PROGRAM} "A"
echo -e "${blue}\n./ScalarConverter 'l'${reset}"
${PROGRAM} "l"
echo -e "${blue}\n./ScalarConverter 'e'${reset}"
${PROGRAM} "e"
echo -e "${blue}\n./ScalarConverter 'x'${reset}"
${PROGRAM} "x"
echo -e "${blue}\n./ScalarConverter '/'${reset}"
${PROGRAM} "/"
echo -e "${blue}\n./ScalarConverter '?'${reset}"
${PROGRAM} "?"
echo -e "${blue}\n./ScalarConverter ':'${reset}"
${PROGRAM} ":"
echo -e "${blue}\n./ScalarConverter '%'${reset}"
${PROGRAM} "%"

echo -e "${purple}\n---------------------------------------------------------------"
echo -e "Int tests..."
echo -e "---------------------------------------------------------------${reset}"

# Test with integer
echo -e "${blue}./ScalarConverter 0${reset}"
${PROGRAM} 0
echo -e "${blue}\n./ScalarConverter 1${reset}"
${PROGRAM} 1
echo -e "${blue}\n./ScalarConverter -1${reset}"
${PROGRAM} -1
echo -e "${blue}\n./ScalarConverter 42${reset}"
${PROGRAM} 42
echo -e "${blue}\n./ScalarConverter -42${reset}"
${PROGRAM} -42
echo -e "${blue}\n./ScalarConverter 65${reset}"
${PROGRAM} 65
echo -e "${blue}\n./ScalarConverter 314${reset}"
${PROGRAM} 314

echo -e "${purple}\n---------------------------------------------------------------"
echo -e "Float tests..."
echo -e "---------------------------------------------------------------${reset}"

# Test with float
echo -e "${blue}./ScalarConverter 0.0f${reset}"
${PROGRAM} 0.0f
echo -e "${blue}\n./ScalarConverter 1.1f${reset}"
${PROGRAM} 1.1f
echo -e "${blue}\n./ScalarConverter -1.1f${reset}"
${PROGRAM} -1.1f
echo -e "${blue}\n./ScalarConverter 42.2f${reset}"
${PROGRAM} 42.2f
echo -e "${blue}\n./ScalarConverter 4.2f${reset}"
${PROGRAM} 4.2f
echo -e "${blue}\n./ScalarConverter -4.2f${reset}"
${PROGRAM} -4.2f
echo -e "${blue}\n./ScalarConverter 65.56f${reset}"
${PROGRAM} 65.56f
echo -e "${blue}\n./ScalarConverter 3.14f${reset}"
${PROGRAM} 3.14f
echo -e "${blue}\n./ScalarConverter 42.0f${reset}"
${PROGRAM} 42.0f

echo -e "${purple}\n---------------------------------------------------------------"
echo -e "Double tests..."
echo -e "---------------------------------------------------------------${reset}"

# Test with double
echo -e "${blue}./ScalarConverter 0.0${reset}"
${PROGRAM} 0.0
echo -e "${blue}\n./ScalarConverter 1.1${reset}"
${PROGRAM} 1.1
echo -e "${blue}\n./ScalarConverter -1.1${reset}"
${PROGRAM} -1.1
echo -e "${blue}\n./ScalarConverter 42.2${reset}"
${PROGRAM} 42.2
echo -e "${blue}\n./ScalarConverter 4.2${reset}"
${PROGRAM} 4.2
echo -e "${blue}\n./ScalarConverter -4.2${reset}"
${PROGRAM} -4.2
echo -e "${blue}\n./ScalarConverter 65.56${reset}"
${PROGRAM} 65.56
echo -e "${blue}\n./ScalarConverter 3.14${reset}"
${PROGRAM} 3.14

echo -e "${purple}\n---------------------------------------------------------------"
echo -e "Pseudo literal tests..."
echo -e "---------------------------------------------------------------${reset}"

# Test with pseudo literal
echo -e "${blue}./ScalarConverter nan${reset}"
${PROGRAM} nan
echo -e "${blue}\n./ScalarConverter nanf${reset}"
${PROGRAM} nanf
echo -e "${blue}\n./ScalarConverter +inf${reset}"
${PROGRAM} +inf
echo -e "${blue}\n./ScalarConverter -inf${reset}"
${PROGRAM} -inf
echo -e "${blue}\n./ScalarConverter +inff${reset}"
${PROGRAM} +inff
echo -e "${blue}\n./ScalarConverter -inff${reset}"
${PROGRAM} -inff

echo -e "${purple}\n---------------------------------------------------------------"
echo -e "Tests finished..."
echo -e "---------------------------------------------------------------${reset}"
