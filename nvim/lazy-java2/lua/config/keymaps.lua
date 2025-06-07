-- Keymaps are automatically loaded on the VeryLazy event
-- Default keymaps that are always set: https://github.com/LazyVim/LazyVim/blob/main/lua/lazyvim/config/keymaps.lua
-- Add any additional keymaps here
vim.g.mapleader = " "
if vim.g.vscode then
  vim.cmd("nmap <leader>v <C-v>")
end
local del = vim.keymap.del
-- del("n", "<leader>l")
-- del("n", "<leader>L")
del("n", "<leader>K")
local map = vim.keymap.set
map({ "i" }, "<C-z>", "<esc>ui", {})
map({ "i" }, "<C-H>", "<C-W>", {})
map({ "n" }, "<leader>ctt", "ciwTrue<esc>", {})
map({ "n" }, "<leader>ctf", "ciwFalse<esc>", {})
map({ "n" }, "<c-a>", "ggVG", {})
map({ "n" }, "<leader>bg", "A<CR><esc>", { ["desc"] = "New line below" })
map({ "n" }, "<leader>bf", "<Cmd>BufferLineCycleNext<CR>", { ["desc"] = "Next buffer" })
map({ "n" }, "<leader>ba", "<Cmd>BufferLineCyclePrev<CR>", { ["desc"] = "Previous buffer" })
map(
  { "n" },
  "<leader>bc",
  "ggVGy<cmd>:wincmd k<CR><cmd>:enew<CR>P",
  { ["desc"] = "Copy buffer to new buffer and window" }
)
map({ "n" }, "x", '"_x', {})
map({ "n", "v" }, "d", '"_d', {})
map({ "n", "v" }, "c", '"_c', {})
map({ "n", "v" }, "D", '"_D', {})
map({ "n", "v" }, "C", '"_C', {})
map({ "n", "v" }, "<leader>v", "<c-v>", { ["desc"] = "Column visual mode" })
map({ "n", "v" }, "<c-z>", "u", {})
map({ "n", "v" }, "<c-x>", "x", {})
map({ "n" }, "<2-LeftMouse>", "yiWi", {})
map({ "n" }, "<c-c>", "y$", {})
map({ "v" }, "<c-c>", "y", {})
map({ "n", "v" }, "<c-t>", ":term<CR>i", {})
map({ "t" }, "<c-n>", "<C-\\><C-n>", {})
map({ "t" }, "<esc>", "<C-\\><C-n>", {})
map({ "t" }, "<c-a>", "<C-\\><C-n>k_yiWi", {})
map({ "t" }, "<c-s>", "<C-\\><C-n>kyyi", {})
vim.api.nvim_set_keymap(
  "n",
  "<home>",
  "col('.') == match(getline('.'),'\\S')+1 ? '0' : '^'",
  { expr = true, noremap = true }
)
vim.api.nvim_set_keymap(
  "i",
  "<home>",
  "col('.') == match(getline('.'),'\\S')+1 ? '<c-o>0' : '<c-o>^'",
  { expr = true, noremap = true }
)
vim.keymap.set("n", "<leader>gw", function()
  vim.cmd("windo diffthis")
end, { noremap = true, desc = "Git diff (w)indows" })
