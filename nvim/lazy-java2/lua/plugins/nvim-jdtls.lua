return {
  "mfussenegger/nvim-jdtls",
  dependencies = "hrsh7th/cmp-nvim-lsp",
  opts = {
    jdtls = function(opts)
      table.insert(opts.cmd, "--java-executable=/usr/lib/jvm/java-1.21.0-openjdk-amd64/bin/java")
      opts.settings = {
        java = {
          configuration = {
            runtimes = {
              {
                name = "JavaSE-17",
                path = "/opt/jdk-17.0.12",
              },
              {
                name = "JavaSE-21",
                path = "/usr/lib/jvm/java-1.21.0-openjdk-amd64",
              },
            },
          },
        },
      }
      return opts
    end,
  },
}
