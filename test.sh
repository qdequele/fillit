nb=1000


while [ $nb -gt 0 ]
do
	./fillit TO_BE_REMOVED/test
	nb=$(( $nb-1 ))
	if [ ! $? -eq 0 ]; then
		exit 2
	fi
done
