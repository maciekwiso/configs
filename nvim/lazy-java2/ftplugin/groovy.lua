local map = vim.keymap.set
local myu = require("config.myutils")

local function run_curr_groovy_test()
  -- Get file name in the current buffer
  local test_name = myu.get_current_class_name()
  local fun_name = myu.get_current_function_name()
  if fun_name ~= "" then
    test_name = test_name .. "." .. fun_name
  end
  myu.term_exec("./gradlew", "test --tests " .. test_name)
end
map({ "n" }, "<leader>tr", "", { ["desc"] = "Run Groovy test", buffer = true, callback = run_curr_groovy_test })
