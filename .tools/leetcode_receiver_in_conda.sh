#!/bin/bash

cd $(dirname $0)/..
echo "WD: $(pwd)"
echo "CONDA_ROOT: $CONDA_ROOT"
echo "CONDA_RENV: $CONDA_RENV"
source $CONDA_ROOT/etc/profile.d/conda.sh
conda activate $CONDA_RENV
python -u ./.tools/leetcode_receiver.py 13013
