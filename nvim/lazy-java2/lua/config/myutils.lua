local M = {}

local function get_current_type(type)
  local ts_utils = require("nvim-treesitter.ts_utils")
  local current_node = ts_utils.get_node_at_cursor()
  if not current_node then
    return ""
  end

  local expr = current_node

  while expr do
    if expr:type() == type then
      break
    end
    expr = expr:parent()
  end

  if not expr then
    return ""
  end
  return expr
end

local function get_identifier(expr)
  for _, child in pairs(expr:named_children()) do
    if child:type() == "identifier" then
      return child
    end
  end
end

function M.get_current_function_name()
  local expr = get_current_type("function_definition")
  local fun_name_expr = get_identifier(expr)
  return vim.treesitter.get_node_text(fun_name_expr, 0)
end

function M.get_current_class_name()
  local expr = get_current_type("class_definition")
  local class_name_epx = get_identifier(expr)
  return vim.treesitter.get_node_text(class_name_epx, 0)
end

local function term_exec_cmd(term, cmd)
  local chan = vim.bo[term.buf].channel
  vim.defer_fn(function()
    vim.fn.chansend(chan, { cmd .. "\r\n" })
  end, 100)
end

local terminals = {}

local function term_del_unused()
  for key, myterm in pairs(terminals) do
    local lines = myterm:lines(2)
    local value = ""
    for i = #lines, 1, -1 do
      value = lines[i]
      if value ~= "" then
        if value:find("^root@") then
          term_exec_cmd(myterm, "exit 0")
          terminals[key] = nil
        end
        break
      end
    end
  end
end

function M.term_exec(cmd, param)
  term_del_unused()
  local myterm = Snacks.terminal.open(nil, {
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
  table.insert(terminals, myterm)
  local res_file_path = "/tmp/" .. string.gsub(param, " ", "_"):gsub("/", "") .. ".txt"
  term_exec_cmd(myterm, cmd .. " " .. param .. " | tee " .. res_file_path)
end
return M
