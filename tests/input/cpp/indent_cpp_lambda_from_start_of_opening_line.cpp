int main()
{
  auto lambda2222222222222222222 = [&]()
    {
        code();
    };

    EXPECT_CALL(*foo, bar)
        .WillOnce(InvokeWithoutArgs([&]() {
                                return 0;
                            }));

    auto lambda3333 = [&]() {
                code();
            };

    auto lambda4 = [&](){ return 0; };

    EXPECT_CALL(*foo, bar)
        .WillOnce(InvokeWithoutArgs([&]() { return 0; }));

    EXPECT_CALL(*foo, bar).WillOnce(InvokeWithoutArgs([&]() { return 0; }));

    EXPECT_CALL(*foo, bar)
        .WillOnce(Return(0))
        .WillOnce(InvokeWithoutArgs([&]() {
                                return 0;
                            }))
        .WillOnce(InvokeWithoutArgs([&]() {
                // foo bar
                                return 0;
                            }))
        .WillRepeatedly(Invoke(
            /**
            * this is a comment block
                */
                    [&](void *fooPtr, int alpha, int beta, int charlie)
                        {
                return 0;
            }
        ));

    auto addPulse = [&] (bool isLastPulse = false) {
        EXPECT_CALL(*foo, bar)
                                                           .WillOnce(Return(false));

        for (unsigned i = 0; i < n; i++) {
            EXPECT_CALL(*foo, bar)
                                        .WillOnce(Return(0))
                        .WillOnce(InvokeWithoutArgs([&]() {
                                return 0;
                            }));
        }
    };

    for (unsigned i = 0; i < n; i++) {
        EXPECT_CALL(*foo, bar)
                                                .WillOnce(Return(0));
    }

    {
    for (unsigned i = 0; i < n; i++) {
        EXPECT_CALL(*foo, bar)
                                                .WillOnce(Return(0))
                .WillOnce(Invoke([]{
                        return 0;
                }))
                                                .WillOnce(Return(0));
    }
    }

    EXPECT_CALL(*foo, bar)
        .WillOnce(Return(true))
        .WillOnce(Invoke([&]()
                 {
                     return true;
                 }));
}

void alignedArgsBraceOnCaptureLine()
{
    auto it = std::find_if(timers.begin(),
                           timers.end(),
                           [&](std::shared_ptr<Timer> timer) {
        return timer->GetId() == id;
    });
}

void alignedArgsBraceOnOwnLine()
{
    auto it = std::find_if(timers.begin(),
                           timers.end(),
                           [&](std::shared_ptr<Timer> timer)
    {
        return timer->GetId() == id;
    });
}

void alignedArgsLambdaFirst()
{
    std::sort(values.begin(), values.end(), [](int a, int b) {
        return a < b;
    });
    registerHandler([this](int code) {
        handle(code);
    },
                    kPriorityHigh);
}

void assignmentWrapBraceOnCaptureLine()
{
    auto executeOpFn =
        [&](const op_t *op, state_t *stateOut) {
        stateOut->count = ctx.count;
        for (unsigned i = 0; i < ctx.count; i++) {
            stateOut->item[i] = op->item[i];
        }
    };
}

void assignmentWrapBraceOnOwnLine()
{
    auto executeOpFn =
        [&](const op_t *op, state_t *stateOut)
    {
        stateOut->count = ctx.count;
    };
}

void assignmentWrapTrailingReturnType()
{
    std::function<bool(int)> isEven =
        [](int value) -> bool {
        return (value % 2) == 0;
    };
}

void assignmentWrapSpecifiers()
{
    auto counter =
        [count = values[0]]() mutable noexcept {
        return ++count;
    };
    auto noCapture =
        [](int value) {
        return value;
    };
}

void returnWrap()
{
    return
        [=]() {
        run();
    };
}

void hangingParenLambdaOnly()
{
    std::for_each(
        values.begin(), values.end(),
        [&](int value) {
        total += value;
    });
    runLater(
        [this]() {
        tick();
    }
        );
}

void hangingParenLambdaThenArgs()
{
    BroadcastObserver observer(
        [this](std::shared_ptr<BroadcastPacket const> pkt, void *arg)
    {
        onBroadcastComplete();
    },
        NULL
        );
}

void nestedCaptureFirstOnLine()
{
    auto outer =
        [&]() {
        auto inner =
            [&](int value) {
            return value + 1;
        };
        return inner(1);
    };
}

void captureNotFirstOnLineUnchanged()
{
    auto f = [&]() {
        run();
    };
    auto it = std::find_if(timers.begin(), timers.end(), [&](std::shared_ptr<Timer> timer) {
        return timer->GetId() == id;
    });
}
