mkdir -p ./bin
for F in ./src/*.c; do 
  gcc -Wall -o ${F%.c} $F
  mv ${F%.c} ./bin/
done
