#!/bin/bash

me=$(cd -- "$(dirname -- "${BASH_SOURCE[0]}")" &>/dev/null && pwd)
what=$1

if [[ "nvim" == "$what" ]]; then
  echo "restoring nvim"
  lazyname='lazy'
  rm -fr ~/.config/nvim/
  rm -fr ~/.local/share/nvim/
  rm -fr ~/.local/state/nvim
  rm -fr ~/.cache/nvim
  git clone https://github.com/LazyVim/starter ~/.config/nvim
  cd ~/.config/nvim/
  cp -r ${me}/nvim/${lazyname}/* .
  rm -rf ~/.config/nvim/.git
fi
