# rm script just in case there is something in bin thats not a binary
for F in ./bin/*; do
  rm $F
done
rmdir ./bin
