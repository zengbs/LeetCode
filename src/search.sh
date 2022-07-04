LEVEL=easy
TAG=array


grep -rnwI . -e "LEVEL: $LEVEL" -l > file-list
while read filename; do grep  "TAG.*$TAG.*" -l "$filename"; done < file-list
rm file-list
