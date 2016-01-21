nb=1000

while [ $nb -gt 0 ]
do
	echo "test : $nb"
	./fillit TO_BE_REMOVED/test7
	if [ ! $? -eq 0 ]; then
		exit 3
	fi
	nb=$(( $nb-1))
done
