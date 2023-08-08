list=$1
folder=$2

while IFS= read -r line; do
    echo "$line"
    sed -i '1d' "$folder/$line"
    git add "$folder/$line"
done < "$list"
