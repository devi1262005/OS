#!/bin/bash
echo "Enter a sentence:"
read sentence
echo "Replacing 'is' with 'was':"
echo "${sentence/is/was}"
