#!/bin/sh
#auto-attacker for Lan Party Security Challenge 2004
#Bob Pelletier

#attacks every one minute
#keeps a score file in correct format for scoreboard

#--------variables------------#
victim="192.168.1.10"
outputfile="machine1.txt"
teamname="TEAM1"

score=500
increment=1
###############################





while [ 1=1 ];
do
clear
echo ""
echo "#----------Auto-Attacker Started-------------#"
echo ""

#-------check for open ports that shouldn't be open--#

	echo "Attacking+"
	nmap -sS $victim > $outputfile
	result=`less $outputfile | grep Elite`	#netcat backdoor on port 31337
	#echo $result

	if [ "$result" != "" ]; then
	  echo VULNERABLE
	  score=`expr $score - $increment`
	fi


	echo "Attacking++"
	result=`less $outputfile | grep hotline`	#1234 backdoor
	#echo $result

	if [ "$result" != "" ]; then
	  echo VULNERABLE
	  score=`expr $score - $increment`
	fi


###############################


#--------check critical services to make sure they are up--#

	echo "Service Check+"
	result=`less $outputfile | grep http`	#Apache
	#echo $result

	if [ "$result" = "" ]; then
	  echo "CRITICAL SERVICE IS DOWN"
	  score=`expr $score - $increment`
	else
	  score=`expr $score + $increment`
	fi


	echo "Service Check++"
	result=`less $outputfile | grep ftp`	#FTP
	#echo $result

	if [ "$result" = "" ]; then
	  echo "CRITICAL SERVICE IS DOWN"
	  score=`expr $score - $increment`
	else
	  score=`expr $score + $increment`
	fi

	echo "Service Check+++"
	result=`less $outputfile | grep ssh`	#SSH
	#echo $result

	if [ "$result" = "" ]; then
	  echo "CRITICAL SERVICE IS DOWN"
	  score=`expr $score - $increment`
	else
	  score=`expr $score + $increment`
	fi

	echo "Service Check++++"
	result=`less $outputfile | grep telnet`	#TELNET
	#echo $result

	if [ "$result" = "" ]; then
	  echo "CRITICAL SERVICE IS DOWN"
	  score=`expr $score - $increment`
	else
	  score=`expr $score + $increment`
	fi

################################


#-----------web attacks-----------#
#variables
url_one="$victim/root.htm"
url_two="$victim/index2.htm"
url_three="$victim/index.php?command3=ls"

	
	echo "Service Configuration Check+"
	
	GET $url_one &> temp
	result=`less temp | grep 'root directory'`
	if [ "$result" != "" ]; then
	  echo "SERVICE MISCONFIGURED"
	  score=`expr $score - $increment`
	fi

	echo "Service Configuration Check++"
	
		
	 
	GET $url_two &> temp
	result=`less temp | grep 404`
	if [ "$result" == "" ] ; then
		result=`GET $url_two | grep "jsmith:smith"`	#checks to see if users and passwords 
		if [ "$result" != "" ] ; then
	  		echo "SERVICE MISCONFIGURED"
		        score=`expr $score - $increment`
		fi
	fi

	echo "Service Configuration Check+++"
	
	GET $url_three &> temp
	result=`less temp | grep "bk2"`		#checks to determine if CMD_EXEC is still in php
	if [ "$result" != "" ]; then
	  echo "SERVICE MISCONFIGURED"
	  score=`expr $score - $increment`
	fi

	echo "SCORE = $score"

###############################


#-------get score from scorebot---------#

localscore=`nc -q 1 $victim 7777` #get score from remote machine
echo "LOCALSCORE = $localscore"
totalscore=`expr $localscore + $score`
echo ""
echo ""
echo "-----"
echo ""
echo $totalscore $teamname



###############################



	sleep 60	#five minute delay
done