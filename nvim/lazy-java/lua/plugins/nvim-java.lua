return {
  "nvim-java/nvim-java",
  keys = {
    { "<leader>j", "", desc = "Java" },
    { "<leader>jg", "<cmd>terminal<cr>igradle build<cr>", desc = "Run gradle build" },
    { "<leader>jm", "<cmd>JavaTestRunCurrentMethod<cr>", desc = "Test Current Method" },
    { "<leader>jc", "<cmd>JavaTestRunCurrentClass<cr>", desc = "Test Current Class" },
  },
}
