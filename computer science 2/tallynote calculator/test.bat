echo begin test
echo should pass
.\TallyNoteCalculator 1549
echo should pass (multiple arguments)
.\TallyNoteCalculator 7309 123 777
echo should fail (multiple arguments, some invalid)
.\TallyNoteCalculator 1234 1200 983 753 695 1a1a1a1
echo should fail (too few arguments)
.\TallyNoteCalculator
echo should fail (invalid argument type)
.\TallyNoteCalculator hello world
echo end test
