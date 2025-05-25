local map = vim.keymap.set
local function get_current_function_name()
  local ts_utils = require("nvim-treesitter.ts_utils")
  local current_node = ts_utils.get_node_at_cursor()
  if not current_node then
    return ""
  end

  local expr = current_node

  while expr do
    if expr:type() == "function_definition" then
      break
    end
    expr = expr:parent()
  end

  if not expr then
    return ""
  end
  return vim.treesitter.get_node_text(expr:child(1), 0)
end

local function run_curr_python_file()
  -- Get file name in the current buffer
  local file_name = vim.api.nvim_buf_get_name(0)
  local fun_name = get_current_function_name()
  if fun_name == "" then
    return
  end
  -- Get terminal codes for running python file
  -- ("i" to enter insert before typing rest of the command)
  local py_cmd =
    vim.api.nvim_replace_termcodes("ipython3 " .. file_name .. " " .. fun_name .. "<cr><c-n>", true, false, true)

  -- Determine terminal window split and launch terminal
  local percent_of_win = 0.4
  local curr_win_height = vim.api.nvim_win_get_height(0) -- Current window height
  local term_height = math.floor(curr_win_height * percent_of_win) -- Terminal height
  vim.cmd(":below " .. term_height .. "split | term") -- Launch terminal (horizontal split)

  -- Press keys to run python command on current file
  vim.api.nvim_feedkeys(py_cmd, "t", false)
end

map(
  { "n" },
  "<leader>dy",
  "",
  { ["desc"] = "Run Python runnable function", buffer = true, callback = run_curr_python_file }
)
