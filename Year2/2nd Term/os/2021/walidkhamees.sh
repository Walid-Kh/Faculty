#! /bin/bash

rm -r Lab1

mkdir Lab1

cp words.txt numbers.txt Lab1

cd Lab1/

paste words.txt numbers.txt > MergedContent.txt

echo The first thre lines of MergedContent.txt $'\n'

head -3 MergedContent.txt 

echo The Sorted File is:$'\n'

sort MergedContent.txt > SortedMergedContent.txt

cat SortedMergedContent.txt

chmod u-r SortedMergedContent.txt 

echo MergedContent with removed Duplicates $'\n'

sort MergedContent.txt | uniq

cat SortedMergedContent.txt | tr '[a-z]' '[A-Z]' > CapitalizedSortedMergedContent.txt

echo $'\n'

echo we previously prevented the reading of the file $'\n'we have to change the premession to be able to do that

echo $'\n'

chmod u+r SortedMergedContent.txt 

echo apprently we can\'t write the output of tr in the same file we are attempting to read. $'\n'so we made a new file

echo Capitalized Sorted Merged Content :$'\n'

cat SortedMergedContent.txt | tr '[a-z]' '[A-Z]' > CapitalizedSortedMergedContent.txt && cat CapitalizedSortedMergedContent.txt

echo $'\n'

echo line numbers starting with “w” and ending with a number in MergedContent.:$'\n'

grep -i '^w.*[0-9]$' MergedContent.txt

echo $'\n'

cat MergedContent.txt | tr 'i' 'o' > NewMergedContent.txt 

paste MergedContent.txt NewMergedContent.txt

