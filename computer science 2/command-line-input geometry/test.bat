echo off
cls
echo: & echo:
echo Begin test
echo: & echo:
echo:  2 dimensional shapes (surface area)"
echo: & echo:

.\project_02.exe  square 123.45                  -quiet
.\project_02.exe  circle 123.45                  -quiet
.\project_02.exe  annulus 100.00 200.00          -quiet

echo: & echo:
echo:   3 dimensional shapes (volume)
echo: & echo:

.\project_02.exe  square_prism 100.00 200.00     -quiet
.\project_02.exe  cylinder 100.00 200.00         -quiet
.\project_02.exe  torus 100.00 200.00            -quiet

echo: & echo:
echo:   negative tests - these should fail
echo: & echo:

.\project_02.exe  xsquare_prism 100.00 200.00     -quiet
.\project_02.exe  cylinder -100.00 200.00         -quiet
.\project_02.exe  torus 300.00 200.00             -quiet

echo: & echo:
echo End test
echo on
