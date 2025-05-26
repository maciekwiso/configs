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
  if MYPYTERM ~= nil then
    local termtext = MYPYTERM:text(1, 10000)
    if string.find(termtext, "Process exited") ~= nil then
      MYPYTERM:destroy()
    end
  end
  MYPYTERM = Snacks.terminal.open("python3 " .. file_name .. " " .. fun_name, {
    interactive = false,
    win = {
      split = "below",
      height = 0.3,
      position = "bottom",
      focusable = true,
      enter = false,
      show = true,
      hide = false,
    },
  })
end

map(
  { "n" },
  "<leader>dy",
  "",
  { ["desc"] = "Run Python runnable function", buffer = true, callback = run_curr_python_file }
)
