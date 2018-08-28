
#!/bin/sh
  #$1 第一个参数的名字,此处为文件名
  # echo "arg_num:$#"
  # echo "shell_name:$0"
  # echo "first_arg:$1"
  # echo "second_arg:$2"
  # echo "args:$@"
  # echo "游戏结算总分:"
  # grep 'GameEnd tid' $1
  # echo "总局数:"
  # grep -c 'GameEnd tid' $1
  # echo "建房信息:"
  # grep  -c 'CreateTable.local' $1
  # echo "建房时间："
  # #grep 'CreateTable.local' $1|grep '([1-9]\d{3})-(0[1-9]|1[0-2])-(0[1-9]|[1-2][0-9]|3[0-1])' 
  # #grep 'CreateTable' $1 |grep '[0-9][0-9][0-9][0-9]-[0-9][0-9]-[0-9][0-9] [0-9][0-9]:[0-9][0-9]:[0-9][0-9]'
  # grep 'CreateTable' $1 |grep '\[[0-9].*\]'  #以[开始，以]结束，中间匹配以数字开始，匹配任意多个字符。


  grep 'GameStart' $1 |grep 'round'>users.txt
  awk -F":" '{print$7}' users.txt>users1.txt
  awk -F"[" '{print$2}' users1.txt>users2.txt
  awk -F"]" '{print$1}' users2.txt >users3.txt

  # grep 'DeleteRoomReq delete player' $1>users.txt
  # awk -F":" '{print$7}' users.txt>users1.txt
  # awk -F " " '{print $1}' users1.txt>users3.txt
    # echo "总房数:"
  # grep -c 'CreateTable.local' $1
  # grep 'Calc_BaseScore uid:\|Calc_HuScore uid:\|GameEnd tid\|Calc_ZhongNiao uid:\|\[(^[0-9])\]' $1
  

#  read -t 30 -p "请输入要查找的信息:" 
# ([0-9]{3}[1-9]|[0-9]{2}[1-9][0-9]{1}|[0-9]{1}[1-9][0-9]{2}|[1-9][0-9]{3})-(((0[13578]|1[02])-(0[1-9]|[12][0-9]|3[01]))|((0[469]|11)-(0[1-9]|[12][0-9]|30))|(02-(0[1-9]|[1][0-9]|2[0-8])))
# echo -e "\n"
# grep $name $1



#$ c="A"; d="fwefewjuew"; e="fewfEFWefwefe"
#$ echo $c | grep -q "^[A-Z]$"
#  while read var
#	do 
#	grep  $var $1
#  done
  


