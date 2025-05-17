-- Keymaps are automatically loaded on the VeryLazy event
-- Default keymaps that are always set: https://github.com/LazyVim/LazyVim/blob/main/lua/lazyvim/config/keymaps.lua
-- Add any additional keymaps here
vim.g.mapleader = " "
if vim.g.vscode then
  vim.cmd("nmap <leader>v <C-v>")
end
local map = vim.keymap.set
map({ "n" }, "x", '"_x', {})
map({ "n", "v" }, "d", '"_d', {})
map({ "n", "v" }, "c", '"_c', {})
map({ "n", "v" }, "D", '"_D', {})
map({ "n", "v" }, "C", '"_C', {})
map({ "n", "v" }, "<leader>v", "<c-v>", {})
map({ "n", "v" }, "<c-z>", "u", {})
map({ "n", "v" }, "<c-x>", "x", {})
map({ "n", "v" }, "<c-c>", "y", {})
