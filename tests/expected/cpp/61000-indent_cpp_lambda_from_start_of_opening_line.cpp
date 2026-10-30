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

    auto lambda4 = [&](){
        return 0;
    };

    EXPECT_CALL(*foo, bar)
        .WillOnce(InvokeWithoutArgs([&]() {
            return 0;
        }));

    EXPECT_CALL(*foo, bar).WillOnce(InvokeWithoutArgs([&]() {
                              return 0;
                          }));

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
