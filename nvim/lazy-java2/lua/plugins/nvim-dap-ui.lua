return {
  "rcarriga/nvim-dap-ui",
  lazy = true,
  Dependencies = { "mfussenegger/nvim-dap", "nvim-neotest/nvim-nio" },
  opts = {
    layouts = {
      {
        -- You can change the order of elements in the sidebar
        elements = {
          -- Provide IDs as strings or tables with "id" and "size" keys
          {
            id = "scopes",
            size = 0.25, -- Can be float or integer > 1
          },
          { id = "breakpoints", size = 0.25 },
          { id = "stacks", size = 0.25 },
          { id = "watches", size = 0.25 },
        },
        size = 40,
        position = "left", -- Can be "left" or "right"
      },
      {
        elements = {
          "repl",
          "console",
        },
        size = 10,
        position = "bottom", -- Can be "bottom" or "top"
      },
      {
        elements = {
          "repl",
        },
        size = 40,
        position = "left", -- Can be "bottom" or "top"
      },
      {
        elements = {
          "console",
        },
        size = 10,
        position = "bottom", -- Can be "bottom" or "top"
      },
    },
  },
  config = function(_, opts)
    require("dapui").setup(opts)
    vim.api.nvim_set_keymap("n", "<leader>du", "", {
      callback = function()
        require("dapui").toggle({ layout = 1, reset = true })
        require("dapui").toggle({ layout = 2, reset = true })
      end,
      desc = "Dap UI",
    })
    vim.api.nvim_set_keymap("n", "<leader>dF", "", {
      callback = function()
        require("dapui").toggle({ layout = 4, reset = true })
      end,
      desc = "Output console",
    })
    vim.api.nvim_set_keymap("n", "<leader>df", "", {
      callback = function()
        require("dapui").toggle({ layout = 3, reset = true })
        require("dapui").toggle({ layout = 4, reset = true })
      end,
      desc = "Output console and tests",
    })
  end,
}
