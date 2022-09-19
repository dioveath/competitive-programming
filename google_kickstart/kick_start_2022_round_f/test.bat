set A=%1
g++ -o main_run %A% -static-libstdc++ -static-libgcc
type sample_%A:.cpp=%.txt | main_run
