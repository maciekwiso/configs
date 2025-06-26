-- Autocmds are automatically loaded on the VeryLazy event
-- Default autocmds that are always set: https://github.com/LazyVim/LazyVim/blob/main/lua/lazyvim/config/autocmds.lua
--
-- Add any additional autocmds here
-- with `vim.api.nvim_create_autocmd`
--
-- Or remove existing autocmds by their group name (which is prefixed with `lazyvim_` for the defaults)
-- e.g. vim.api.nvim_del_augroup_by_name("lazyvim_wrap_spell")
local search_regs = {}

local function search_bufleave()
  search_regs[vim.fn.bufname()] = vim.fn.getreg("/")
end

local function search_bufenter()
  vim.fn.setreg("/", search_regs[vim.fn.bufname()])
end

vim.api.nvim_create_autocmd({ "BufLeave" }, {
  pattern = "*",
  callback = search_bufleave,
})

vim.api.nvim_create_autocmd({ "BufEnter" }, {
  pattern = "*",
  callback = search_bufenter,
})
