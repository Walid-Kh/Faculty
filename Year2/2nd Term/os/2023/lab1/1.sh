#!/bin/bash
echo "Mohamed Maher Amin"
rm -r lab1
 mkdir lab1
 cp numbers.txt lab1
 cp words.txt lab1
 cd lab1
touch MergedContent.txt
paste numbers.txt words.txt >> MergedContent.txt
cat MergedContent.txt | head -3
touch SortedMergedContent.txt
sort MergedContent.txt >> SortedMergedContent.txt
echo "The sorted file is :"
cat SortedMergedContent.txt
chmod a-r SortedMergedContent.txt
 sort MergedContent.txt | uniq
 cat SortedMergedContent.txt | tr '[a-z]' '[A-Z]'
 echo "the permission denied because the file permission is set that no one car read it"
 chmod a+r SortedMergedContent.txt
 cat SortedMergedContent.txt | tr '[a-z]' '[A-Z]'
 grep -n "^w.*[0-9]$" MergedContent.txt
 touch NewMergedContent.txt
 cat MergedContent.txt | tr 'i.' 'o' >> NewMergedContent.txt
 paste MergedContent.txt NewMergedContent.txt