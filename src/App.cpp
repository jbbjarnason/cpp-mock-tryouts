#include "App.hpp"
#include <SmurfActions.hpp>

int App::init() {
    _signals = std::make_unique<asio::signal_set>(
        _loop,
        SIGINT,
        SIGTERM,
        SIGQUIT
    );
    _signals->async_wait(exit());

    _smurf = std::make_unique<Smurfs::Smurf>();
    auto walk {Smurfs::Walking()};
    _smurf->doAction(walk);

    return 0;
}

int App::run() {
    if (_loop.run() <= 0)
        return -1;
    return 0;
}

std::function<void(const asio::error_code &, const int &)> App::exit() {
    return [this](auto, auto){
        _loop.stop();
    };
}
