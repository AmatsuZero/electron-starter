const vite = require("vite");
const vue = require("@vitejs/plugin-vue");

const dev = {
  server: null,
  serverPort: 1600,
  async createServer() {
    const options = {
      configFile: false,
      root: process.cwd(),
      server: {
        port: this.serverPort,
      },
      plugins: [vue()],
    };
    this.server = await vite.createServer(options);
    await this.server.listen();
  },
  async start() {
    await this.createServer();
  }
};

dev.start();