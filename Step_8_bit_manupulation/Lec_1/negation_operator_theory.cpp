/*
the negation operation "~" this simply flips all bits and store the result. nothing much.. just simple flip all bits.
Let's work out with case of positive number
consider 
n = 5  = 00000000000000000000000000000101
   now,
     ~n = 11111111111111111111111111111010  
this is what is stored inside computer, now upon reading this number when we require it somewhere to be printed or anything. the computer looks at the 31st bit and sees it is set, thus the number is negative, thus a negative sign will be put and now to fetch its value, computer perform 2's complement. So,
              00000000000000000000000000000101   <--- 1's compliment
              00000000000000000000000000000110   <--- 2's compliment
we can see 2's compliment provided the value 6. so the value fetched when printing ~n will be -6 

Let's work out with case of negative number
consider n = -5
                5 = 00000000000000000000000000000101
               -5 = 11111111111111111111111111111011   (stored in computer in 2's compliment)
   now,
~n = ~(-5) = 00000000000000000000000000000100    (just flipped all bits)
this is what is stored inside computer, now upon reading this number when we require it somewhere to be printed or anything. the computer looks at the 31st bit and sees it is not set, thus the number is positive, thus no sign will be put and its value can be fetched directly
~n = ~(-5) = 00000000000000000000000000000100  = 4
so the fetched value is 4 and the number is positive so the value fetched while printing ~n will be +4 or simply 4          