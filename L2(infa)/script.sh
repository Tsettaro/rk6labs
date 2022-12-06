#!/bin/bash
# Программа перекодировки текста КОИ-8 в cp1251

# Функция построения таблицы перекодировки из файла-таблицы
function code
{
  # Подстановка номеров букв
	num=`cat $1`
  # Конкатенация кодов для строчных и заглавных букв cp1251
	for i in ${num[@]}; do
		low="$low\3$i"
		high="$high\3$(expr $i + 40)"
	done
  # Конкатенация кодов для букв 'Ё' и 'ё'
	low="\270$low"
	high="\250$high"
	echo $high$low
  # Возврат из функции code
  return
}

# Диагностика аргументов командной строки
# Контроль числа аргументов
if [ $# -ne 3 ]
then
	echo "Not enough arguments. Please try again." >&2
	exit -1
fi

# Контроль существования и доступа чтения к файлу-таблице
if [ ! -r $1 ]
then
	echo "Table with codes can't be read or doesn't exist." >&2
	exit -2
fi

# Контроль доступа чтения для входного файла
if [ ! -r $2 ]
then
	echo "File can't be read or doesn't exist." >&2
	exit -3
fi

# Контроль маршрутного имени для выходного файла
CUR=`pwd` # Маршрутное имя текущего каталога
OUT=`expr $2 : '\(.*\/\)' \| $CUR`

# Контроль каталога по (пере)записи
if [ ! -w $OUT ]
then
	echo "$OUT: permission denied to write" >&2
	exit -4
fi
# Проверка, что выходной файл нет каталог
if test -d $3
then
	echo "$3 is directory" >&2
	exit -5
fi

# Контроль перезаписи выходного файла
if test -e $3
then
    if [ ! -w $3 ]  # Контроль доступа перезаписи для выходного файла
    then
        echo "$3: permission denied to write" >&2
        exit -6
    fi
	while true
	do
    # Вывод сообщения о возможности перезаписи файла
		read -p "File $3 exists. Do you want to rewrite this file? [y/n]: " ans
		case $ans in
			[Yy] ) break;;
			[Nn] ) exit 0;;
			* ) echo "Answer: no or yes"
		esac
	done
fi
# Транслитерация кодов koi8 в cp1251
cat $2 | tr "\263\300-\337\243\340-\377" `code $1` > $3