void app() {
    unsigned int r = simRand();
    simPutPixel(5, 5, r);
    simFlush();
}