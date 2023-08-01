#!/bin/bash

# Установка языка терминала
LANG=en_us_8859_1

# Получение текущего года
NOW=`date "+%Y"`

# Проверка на количество аргументов
case $# in
	1)	DY=$1/$NOW;;
	2)	expr $2 + 1 &>/dev/null
		if [ $? -ne 0 ]; then
			echo "$2 is not correct"
			exit -1
		fi

		# Проверка на правильность года (он должен быть ≥ 0)
		if [ $2 -lt 0 ]; then
			echo "$2 less than 0"
			exit -5
		fi
		DY=$1/$2;;
	*)	echo "Incorrect number of arguments"
		exit -2
esac

# Проверка на правильность числа
expr $1 + 0 &>/dev/null
if [ $? -ne 0 -o $1 -gt 31 -o $1 -lt 1 ]; then
	echo "$1 is not correct"
	exit -3
fi

DAYS=("Monday – " "Tuesday – " "Wednesday – " "Thursday – " "Friday – " "Saturday – " "Sunday – ")

month=(01 02 03 04 05 06 07 08 09 10 11 12)

# Индекс следующего элемента массива month
c=1


# M1 – текущий месяц из массива month
for M1 in ${month[@]}
do
    # M2 – следующие после M1 месяцы
	for M2 in ${month[@]:$c}
	do
		# Проверка на существование дат
		date -d "$M1/$DY" &> /dev/null
        if [ $? -ne 0 ]; then
			continue
        fi

		date -d "$M2/$DY" &> /dev/null
		if [ $? -ne 0 ]; then
			continue
		fi

        # Дни недели двух дней разных месяцев
		FIRST=`date -d "$M1/$DY" +%a`
		SECOND=`date -d "$M2/$DY" +%a`

          # Проверка на равенство дней недели
		if [ $FIRST = $SECOND ]; then
        	ABR_1=`date -d "$M1/$DY" +%b`
	    	ABR_2=`date -d "$M2/$DY" +%b`
	    	INDEX=`expr $(date -d "$M1/$DY" +%u) - 1`
	    	DAYS[INDEX]="${DAYS[INDEX]}$ABR_1 and $ABR_2; "
		fi
	done
	c=`expr $c + 1`
done

# Вывод дней недели с соответствующими месяцами
for j in "${DAYS[@]}"
do
    echo $j
done
    
