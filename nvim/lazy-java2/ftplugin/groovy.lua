local map = vim.keymap.set
local function get_current_type_name(type, childno)
  local ts_utils = require("nvim-treesitter.ts_utils")
  local current_node = ts_utils.get_node_at_cursor()
  print(current_node)
  if not current_node then
    return ""
  end

  local expr = current_node

  while expr do
    print(expr:type())
    if expr:type() == type then
      break
    end
    expr = expr:parent()
  end

  if not expr then
    return ""
  end
  return vim.treesitter.get_node_text(expr:child(childno), 0)
end

local function run_curr_groovy_test()
  -- Get file name in the current buffer
  local file_name = get_current_type_name("class_definition", 1)
  local fun_name = get_current_type_name("function_definition", 2)
  if fun_name == "" then
    return
  end
  -- Get terminal codes for running file
  -- ("i" to enter insert before typing rest of the command)
  print(fun_name)
  local py_cmd = vim.api.nvim_replace_termcodes(
    "i./gradlew test --tests " .. file_name .. "." .. fun_name .. "<cr><c-n>",
    true,
    false,
    true
  )

  -- Determine terminal window split and launch terminal
  local percent_of_win = 0.4
  local curr_win_height = vim.api.nvim_win_get_height(0) -- Current window height
  local term_height = math.floor(curr_win_height * percent_of_win) -- Terminal height
  vim.cmd(":below " .. term_height .. "split | term") -- Launch terminal (horizontal split)

  -- Press keys to run command on current file
  vim.api.nvim_feedkeys(py_cmd, "t", false)
end
map({ "n" }, "<leader>tr", "", { ["desc"] = "Run Groovy test", buffer = true, callback = run_curr_groovy_test })
