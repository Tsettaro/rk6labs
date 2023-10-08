#!/bin/bash

# Проверка на количество аргументов
if [ $# -ne 2 ]; then
	echo "Incorrect number of arguments"
	exit -1
fi

# Исходная строка 
STR=$1

# Искомый символ
FIND=$2

# Длина второго аргумента без учёта посторонних символов
FIND_LEN=`expr $2 : "[?\!.,[:alnum:]]*"`

# Проверка на символ во втором аргументе
if [ $FIND_LEN -ne 1 ]; then
	echo "Extraneous characters detected!"
	exit -2
fi

# Удаление всех символов (кроме одного из второго аргумента) из строки
# первого аргумента + подсчёт символов оставшейся строки
exit `tr -cd $FIND <<< $STR | wc -m`
