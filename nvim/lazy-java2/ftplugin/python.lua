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

local function run_curr_python_fun()
  -- Get file name in the current buffer
  local file_name = vim.api.nvim_buf_get_name(0)
  local fun_name = get_current_function_name()
  if fun_name == "" then
    return
  end

  if MYPYTERM ~= nil then
    local lines = MYPYTERM:lines(2)
    local value = ""
    for i = #lines, 1, -1 do
      value = lines[i]
      if value ~= "" then
        -- print(i .. ": " .. value)
        if value:find("^root@") then
          local chan = vim.bo[MYPYTERM.buf].channel
          vim.defer_fn(function()
            vim.fn.chansend(chan, { "exit 0\r\n" })
          end, 100)
        end
        break
      end
    end
  end
  MYPYTERM = Snacks.terminal.open(nil, {
    auto_insert = false,
    win = {
      split = "below",
      height = 0.4,
      position = "bottom",
      focusable = true,
      enter = false,
      show = true,
      hide = false,
    },
  })
  local chan = vim.bo[MYPYTERM.buf].channel
  local cmd_ending = file_name .. " " .. fun_name
  local res_file_path = "/tmp/" .. string.gsub(cmd_ending, " ", "_"):gsub("/", "")
  vim.defer_fn(function()
    vim.fn.chansend(chan, { "python3 -u " .. cmd_ending .. " | tee " .. res_file_path .. "\r\n" })
  end, 100)
end
map(
  { "n" },
  "<leader>dy",
  "",
  { ["desc"] = "Run Python runnable function", buffer = true, callback = run_curr_python_fun }
)
