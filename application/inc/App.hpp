#pragma once

#include <Smurf.hpp>
#include <functional>
#include <asio/io_context.hpp>
#include <asio/signal_set.hpp>

class App {
public:
    App() = default;
    ~App() = default;
    int init();
    int run();
private:
    std::function<void(const asio::error_code &, const int &)> exit();
    asio::io_context _loop;
    std::unique_ptr<asio::signal_set> _signals;

    std::unique_ptr<Smurfs::Smurf> _smurf;
};