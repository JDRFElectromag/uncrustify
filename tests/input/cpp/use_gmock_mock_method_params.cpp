class MockFoo {
public:
    MOCK_METHOD(void, a, (cfg_t *params));
    MOCK_METHOD(void, b, (uint8_t id, cfg_t *out), (override));
    MOCK_METHOD(cfg_t *, c, (const cfg_t *const p, int n));
    MOCK_METHOD(void, d, (cfg_t **pp, cfg_t &r));
    MOCK_METHOD(void, e, (cfg_t &r));
    MOCK_METHOD(void, f, (cfg_t * p));
    MOCK_METHOD1(g, void(cfg_t *p));
    MOCK_CONST_METHOD1(h, int(cfg_t *p));
    MOCK_METHOD2_T(i, int(cfg_t *p, int n));
    MOCK_METHOD2(k, ai_buffer*(ai_handle n, ai_u16 *b));
    MOCK_METHOD1(l, const size_t *(int n));
    MOCK_METHOD1(m, cfg_t **(int n));
    MOCK_METHOD(volatile void *, n, ());
};

void j()
{
    int z = a*b;
    MOCK_METHODS(a*b);
}
