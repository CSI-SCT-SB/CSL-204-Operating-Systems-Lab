echo "Enter a Number"
read n
i=`expr $n - 1`
p=1

while [ $i -ge 1 ]
do
n=`expr $n \* $i`
i=`expr $i - 1`
done

echo "The Factorial of the given Number is $n"