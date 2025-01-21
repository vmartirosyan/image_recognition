#!/bin/bash

# File containing URLs to download
url_file="flags.txt"

# Iterate over each line in the file
while IFS= read -r line; do
  # Check if the line is not empty
  if [[ -n "$line" ]]; then
    # Download the URL using wget
    wget -c "$line" 2>/dev/null

    # Check if the download was successful
    if [[ -f "${line##*/}" ]]; then
      # Get the original filename
      original_filename="${line##*/}"

      # Trim the first 8 characters from the filename
      trimmed_filename="${original_filename:8}"

      # Rename the downloaded file
      mv "${original_filename}" "${trimmed_filename}"

      convert -depth 32 ${trimmed_filename} "${trimmed_filename}.bmp"

      rm -f "${trimmed_filename}"

      echo "Downloaded and renamed: ${trimmed_filename}"
    else
      echo "Failed to download: $line"
    fi
  fi
done < "$url_file"