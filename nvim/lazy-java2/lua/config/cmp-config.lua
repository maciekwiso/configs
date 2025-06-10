require("cmp").setup({
  snippet = {
    -- Exclusive to LuaSnip, check nvim-cmp documentation for usage with a different snippet engine
    expand = function(args)
      require("luasnip").lsp_expand(args.body)
    end,
  },
  mapping = {
    -- Sample but necessary mappings, read nvim-cmp documentation to customize them
    ["<C-e>"] = require("cmp").mapping.abort(),
    ["<CR>"] = require("cmp").mapping.confirm(),
    ["<C-n>"] = require("cmp").mapping.select_next_item(),
    ["<C-p>"] = require("cmp").mapping.select_prev_item(),
  },
  sources = {
    { name = "nvim_lsp" },
    { name = "path" },
  },
})

local ls = require("luasnip")
ls.config.set_config({
  history = false,
  updateevents = "TextChanged,TextChangedI",
})

vim.keymap.set({ "i", "s" }, "<c-l>", function()
  if ls.expand_or_jumpable() then
    ls.expand_or_jump()
  end
end, { silent = true })

vim.keymap.set({ "i", "s" }, "<c-j>", function()
  if ls.jumpable(-1) then
    ls.jump(-1)
  end
end, { silent = true })
