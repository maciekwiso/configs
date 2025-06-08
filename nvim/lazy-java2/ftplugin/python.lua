local map = vim.keymap.set
local myu = require("config.myutils")

local function run_curr_python_fun()
  -- Get file name in the current buffer
  local file_name = vim.api.nvim_buf_get_name(0)
  local fun_name = myu.get_current_function_name()
  if fun_name == "" then
    return
  end
  local cmd_ending = file_name .. " " .. fun_name
  local cmd_beg = "python3 -u"
  myu.term_exec(cmd_beg, cmd_ending)
end
map(
  { "n" },
  "<leader>dy",
  "",
  { ["desc"] = "Run Python runnable function", buffer = true, callback = run_curr_python_fun }
)
