echo begin test
echo should pass
.\WorkingWithArrays  55 6 8 4 52 1 5 13 0 8 9 48 11 
echo should pass
.\WorkingWithArrays  0 0 0 0 0 0 0 0 0 0 0 0 1 2 3 0 0 0 0 0 
echo should pass
.\WorkingWithArrays  -1 -2 -3 -4 -5 -6 -7 -8 -9 -10
echo should fail (too few arguments)
.\WorkingWithArrays  
echo should fail (too many arguments)
.\WorkingWithArrays   0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 1
echo end test
