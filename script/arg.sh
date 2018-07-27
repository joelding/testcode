param=1
for arg in $@
do
	if [ $param -eq 1 ] ; then
		echo 'reach $param';
	fi 
	case $arg in
		"-osmem")
			echo '-osmem';
			;;
		*)
			echo '-default';
			;;
	esac
done
