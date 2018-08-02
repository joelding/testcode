param=1

for arg in $@
do
	if [ $param -eq 1 ] ; then
		echo 'reach $param';
	fi 
	case $arg in
		"-osmem")
			echo '-osmem';
			echo $arg;
			;;
		*)
			echo "unknown parameter $arg";
			exit;
			;;
	esac
done

# if argument number is less than 1
if [ $# -lt 1 ]; then
	echo 'less than 1'
	exit 0
fi

