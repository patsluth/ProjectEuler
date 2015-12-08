//
//  main.cpp
//  ProjectEuler
//
//  Created by Pat Sluth on 2015-09-09.
//  Copyright (c) 2015 Pat Sluth. All rights reserved.
//

#include <iostream>
#include <stdio.h>     // for fprintf(), sscanf(), etc.

#include "problem_factory.h"
#include "problem_base.h"

#ifdef RELEASE

#include "problem_1.h"
#include "problem_2.h"
#include "problem_3.h"
#include "problem_4.h"
#include "problem_5.h"
#include "problem_6.h"
#include "problem_7.h"
#include "problem_8.h"
#include "problem_9.h"
#include "problem_10.h"
#include "problem_11.h"
#include "problem_12.h"
#include "problem_13.h"
#include "problem_14.h"
#include "problem_15.h"
#include "problem_16.h"
#include "problem_17.h"
#include "problem_18.h"
//#include "problem_19.h"
#include "problem_20.h"
#include "problem_21.h"
//#include "problem_22.h"
#include "problem_23.h"
//#include "problem_24.h"
#include "problem_25.h"
//#include "problem_26.h"
#include "problem_27.h"
//#include "problem_28.h"
//#include "problem_29.h"
#include "problem_30.h"
//#include "problem_31.h"
//#include "problem_32.h"
//#include "problem_33.h"
#include "problem_34.h"
#include "problem_35.h"
#include "problem_36.h"
#include "problem_37.h"
//#include "problem_38.h"
#include "problem_39.h"
//#include "problem_40.h"
//#include "problem_41.h"
#include "problem_42.h"
//#include "problem_43.h"
#include "problem_44.h"
#include "problem_45.h"
#include "problem_46.h"
//#include "problem_47.h"
#include "problem_48.h"
//#include "problem_49.h"
//#include "problem_50.h"
//#include "problem_51.h"
#include "problem_52.h"
#include "problem_53.h"
//#include "problem_54.h"
//#include "problem_55.h"
//#include "problem_56.h"
//#include "problem_57.h"
//#include "problem_58.h"
//#include "problem_59.h"
#include "problem_60.h"
#include "problem_61.h"
//#include "problem_62.h"
//#include "problem_63.h"
//#include "problem_64.h"
//#include "problem_65.h"
//#include "problem_66.h"
#include "problem_67.h"
//#include "problem_68.h"
//#include "problem_69.h"
//#include "problem_70.h"
//#include "problem_71.h"
//#include "problem_72.h"
//#include "problem_73.h"
#include "problem_74.h"
//#include "problem_75.h"
#include "problem_76.h"
//#include "problem_77.h"
//#include "problem_78.h"
//#include "problem_79.h"
#include "problem_80.h"
#include "problem_81.h"
#include "problem_82.h"
//#include "problem_83.h"
//#include "problem_84.h"
//#include "problem_85.h"
//#include "problem_86.h"
#include "problem_87.h"
//#include "problem_88.h"
//#include "problem_89.h"
//#include "problem_90.h"
//#include "problem_91.h"
#include "problem_92.h"
//#include "problem_93.h"
//#include "problem_94.h"
#include "problem_95.h"
//#include "problem_96.h"
//#include "problem_97.h"
//#include "problem_98.h"
#include "problem_99.h"
//#include "problem_100.h"
//#include "problem_101.h"
//#include "problem_102.h"
//#include "problem_103.h"
//#include "problem_104.h"
//#include "problem_105.h"
//#include "problem_106.h"
//#include "problem_107.h"
//#include "problem_108.h"
//#include "problem_109.h"
//#include "problem_110.h"
//#include "problem_111.h"
//#include "problem_112.h"
//#include "problem_113.h"
//#include "problem_114.h"
//#include "problem_115.h"
//#include "problem_116.h"
//#include "problem_117.h"
//#include "problem_118.h"
//#include "problem_119.h"
//#include "problem_120.h"
//#include "problem_121.h"
//#include "problem_122.h"
//#include "problem_123.h"
//#include "problem_124.h"
//#include "problem_125.h"
//#include "problem_126.h"
//#include "problem_127.h"
//#include "problem_128.h"
//#include "problem_129.h"
//#include "problem_130.h"
//#include "problem_131.h"
//#include "problem_132.h"
//#include "problem_133.h"
//#include "problem_134.h"
//#include "problem_135.h"
//#include "problem_136.h"
//#include "problem_137.h"
//#include "problem_138.h"
//#include "problem_139.h"
//#include "problem_140.h"
//#include "problem_141.h"
//#include "problem_142.h"
//#include "problem_143.h"
//#include "problem_144.h"
//#include "problem_145.h"
//#include "problem_146.h"
//#include "problem_147.h"
//#include "problem_148.h"
//#include "problem_149.h"
//#include "problem_150.h"
//#include "problem_151.h"
//#include "problem_152.h"
//#include "problem_153.h"
//#include "problem_154.h"
//#include "problem_155.h"
//#include "problem_156.h"
//#include "problem_157.h"
//#include "problem_158.h"
//#include "problem_159.h"
//#include "problem_160.h"
//#include "problem_161.h"
//#include "problem_162.h"
//#include "problem_163.h"
//#include "problem_164.h"
//#include "problem_165.h"
//#include "problem_166.h"
//#include "problem_167.h"
//#include "problem_168.h"
//#include "problem_169.h"
//#include "problem_170.h"
//#include "problem_171.h"
//#include "problem_172.h"
//#include "problem_173.h"
//#include "problem_174.h"
//#include "problem_175.h"
//#include "problem_176.h"
//#include "problem_177.h"
//#include "problem_178.h"
//#include "problem_179.h"
//#include "problem_180.h"
//#include "problem_181.h"
//#include "problem_182.h"
//#include "problem_183.h"
//#include "problem_184.h"
//#include "problem_185.h"
//#include "problem_186.h"
//#include "problem_187.h"
//#include "problem_188.h"
//#include "problem_189.h"
//#include "problem_190.h"
//#include "problem_191.h"
//#include "problem_192.h"
//#include "problem_193.h"
//#include "problem_194.h"
//#include "problem_195.h"
//#include "problem_196.h"
//#include "problem_197.h"
//#include "problem_198.h"
//#include "problem_199.h"
//#include "problem_200.h"
//#include "problem_201.h"
//#include "problem_202.h"
//#include "problem_203.h"
//#include "problem_204.h"
//#include "problem_205.h"
//#include "problem_206.h"
//#include "problem_207.h"
//#include "problem_208.h"
//#include "problem_209.h"
//#include "problem_210.h"
//#include "problem_211.h"
//#include "problem_212.h"
//#include "problem_213.h"
//#include "problem_214.h"
//#include "problem_215.h"
//#include "problem_216.h"
//#include "problem_217.h"
//#include "problem_218.h"
//#include "problem_219.h"
//#include "problem_220.h"
//#include "problem_221.h"
//#include "problem_222.h"
//#include "problem_223.h"
//#include "problem_224.h"
//#include "problem_225.h"
//#include "problem_226.h"
//#include "problem_227.h"
//#include "problem_228.h"
//#include "problem_229.h"
//#include "problem_230.h"
//#include "problem_231.h"
//#include "problem_232.h"
//#include "problem_233.h"
//#include "problem_234.h"
//#include "problem_235.h"
//#include "problem_236.h"
//#include "problem_237.h"
//#include "problem_238.h"
//#include "problem_239.h"
//#include "problem_240.h"
//#include "problem_241.h"
//#include "problem_242.h"
//#include "problem_243.h"
//#include "problem_244.h"
//#include "problem_245.h"
//#include "problem_246.h"
//#include "problem_247.h"
//#include "problem_248.h"
//#include "problem_249.h"
//#include "problem_250.h"
//#include "problem_251.h"
//#include "problem_252.h"
//#include "problem_253.h"
//#include "problem_254.h"
//#include "problem_255.h"
//#include "problem_256.h"
//#include "problem_257.h"
//#include "problem_258.h"
//#include "problem_259.h"
//#include "problem_260.h"
//#include "problem_261.h"
//#include "problem_262.h"
//#include "problem_263.h"
//#include "problem_264.h"
//#include "problem_265.h"
//#include "problem_266.h"
//#include "problem_267.h"
//#include "problem_268.h"
//#include "problem_269.h"
//#include "problem_270.h"
//#include "problem_271.h"
//#include "problem_272.h"
//#include "problem_273.h"
//#include "problem_274.h"
//#include "problem_275.h"
//#include "problem_276.h"
//#include "problem_277.h"
//#include "problem_278.h"
//#include "problem_279.h"
//#include "problem_280.h"
//#include "problem_281.h"
//#include "problem_282.h"
//#include "problem_283.h"
//#include "problem_284.h"
//#include "problem_285.h"
//#include "problem_286.h"
//#include "problem_287.h"
//#include "problem_288.h"
//#include "problem_289.h"
//#include "problem_290.h"
//#include "problem_291.h"
//#include "problem_292.h"
//#include "problem_293.h"
//#include "problem_294.h"
//#include "problem_295.h"
//#include "problem_296.h"
//#include "problem_297.h"
//#include "problem_298.h"
//#include "problem_299.h"
//#include "problem_300.h"
//#include "problem_301.h"
//#include "problem_302.h"
//#include "problem_303.h"
//#include "problem_304.h"
//#include "problem_305.h"
//#include "problem_306.h"
//#include "problem_307.h"
//#include "problem_308.h"
//#include "problem_309.h"
//#include "problem_310.h"
//#include "problem_311.h"
//#include "problem_312.h"
//#include "problem_313.h"
//#include "problem_314.h"
//#include "problem_315.h"
//#include "problem_316.h"
//#include "problem_317.h"
//#include "problem_318.h"
//#include "problem_319.h"
//#include "problem_320.h"
//#include "problem_321.h"
//#include "problem_322.h"
//#include "problem_323.h"
//#include "problem_324.h"
//#include "problem_325.h"
//#include "problem_326.h"
//#include "problem_327.h"
//#include "problem_328.h"
//#include "problem_329.h"
//#include "problem_330.h"
//#include "problem_331.h"
//#include "problem_332.h"
//#include "problem_333.h"
//#include "problem_334.h"
//#include "problem_335.h"
//#include "problem_336.h"
//#include "problem_337.h"
//#include "problem_338.h"
//#include "problem_339.h"
//#include "problem_340.h"
//#include "problem_341.h"
//#include "problem_342.h"
//#include "problem_343.h"
//#include "problem_344.h"
//#include "problem_345.h"
//#include "problem_346.h"
//#include "problem_347.h"
//#include "problem_348.h"
//#include "problem_349.h"
//#include "problem_350.h"
//#include "problem_351.h"
//#include "problem_352.h"
//#include "problem_353.h"
//#include "problem_354.h"
//#include "problem_355.h"
//#include "problem_356.h"
//#include "problem_357.h"
//#include "problem_358.h"
//#include "problem_359.h"
//#include "problem_360.h"
//#include "problem_361.h"
//#include "problem_362.h"
//#include "problem_363.h"
//#include "problem_364.h"
//#include "problem_365.h"
//#include "problem_366.h"
//#include "problem_367.h"
//#include "problem_368.h"
//#include "problem_369.h"
//#include "problem_370.h"
//#include "problem_371.h"
//#include "problem_372.h"
//#include "problem_373.h"
//#include "problem_374.h"
//#include "problem_375.h"
//#include "problem_376.h"
//#include "problem_377.h"
//#include "problem_378.h"
//#include "problem_379.h"
//#include "problem_380.h"
//#include "problem_381.h"
//#include "problem_382.h"
//#include "problem_383.h"
//#include "problem_384.h"
//#include "problem_385.h"
//#include "problem_386.h"
//#include "problem_387.h"
//#include "problem_388.h"
//#include "problem_389.h"
//#include "problem_390.h"
//#include "problem_391.h"
//#include "problem_392.h"
//#include "problem_393.h"
//#include "problem_394.h"
//#include "problem_395.h"
//#include "problem_396.h"
//#include "problem_397.h"
//#include "problem_398.h"
//#include "problem_399.h"
//#include "problem_400.h"
//#include "problem_401.h"
//#include "problem_402.h"
//#include "problem_403.h"
//#include "problem_404.h"
//#include "problem_405.h"
//#include "problem_406.h"
//#include "problem_407.h"
//#include "problem_408.h"
//#include "problem_409.h"
//#include "problem_410.h"
//#include "problem_411.h"
//#include "problem_412.h"
//#include "problem_413.h"
//#include "problem_414.h"
//#include "problem_415.h"
//#include "problem_416.h"
//#include "problem_417.h"
//#include "problem_418.h"
//#include "problem_419.h"
//#include "problem_420.h"
//#include "problem_421.h"
//#include "problem_422.h"
//#include "problem_423.h"
//#include "problem_424.h"
//#include "problem_425.h"
//#include "problem_426.h"
//#include "problem_427.h"
//#include "problem_428.h"
//#include "problem_429.h"
//#include "problem_430.h"
//#include "problem_431.h"
//#include "problem_432.h"
//#include "problem_433.h"
//#include "problem_434.h"
//#include "problem_435.h"
//#include "problem_436.h"
//#include "problem_437.h"
//#include "problem_438.h"
//#include "problem_439.h"
//#include "problem_440.h"
//#include "problem_441.h"
//#include "problem_442.h"
//#include "problem_443.h"
//#include "problem_444.h"
//#include "problem_445.h"
//#include "problem_446.h"
//#include "problem_447.h"
//#include "problem_448.h"
//#include "problem_449.h"
//#include "problem_450.h"
//#include "problem_451.h"
//#include "problem_452.h"
//#include "problem_453.h"
//#include "problem_454.h"
//#include "problem_455.h"
//#include "problem_456.h"
//#include "problem_457.h"
//#include "problem_458.h"
//#include "problem_459.h"
//#include "problem_460.h"
//#include "problem_461.h"
//#include "problem_462.h"
//#include "problem_463.h"
//#include "problem_464.h"
//#include "problem_465.h"
//#include "problem_466.h"
//#include "problem_467.h"
//#include "problem_468.h"
//#include "problem_469.h"
//#include "problem_470.h"
//#include "problem_471.h"
//#include "problem_472.h"
//#include "problem_473.h"
//#include "problem_474.h"
//#include "problem_475.h"
//#include "problem_476.h"
//#include "problem_477.h"
//#include "problem_478.h"
//#include "problem_479.h"
//#include "problem_480.h"
//#include "problem_481.h"
//#include "problem_482.h"
//#include "problem_483.h"
//#include "problem_484.h"
//#include "problem_485.h"
//#include "problem_486.h"
//#include "problem_487.h"
//#include "problem_488.h"
//#include "problem_489.h"
//#include "problem_490.h"
//#include "problem_491.h"
//#include "problem_492.h"
//#include "problem_493.h"
//#include "problem_494.h"
//#include "problem_495.h"
//#include "problem_496.h"
//#include "problem_497.h"
//#include "problem_498.h"
//#include "problem_499.h"
//#include "problem_500.h"

#else

#include "problem_29.h"
#include "problem_60.h"

#endif

static void registerProblems()
{
#ifdef RELEASE
    
    PROBLEM_FACTORY_REGISTER_CLASS(problem_1);
    PROBLEM_FACTORY_REGISTER_CLASS(problem_2);
    PROBLEM_FACTORY_REGISTER_CLASS(problem_3);
    PROBLEM_FACTORY_REGISTER_CLASS(problem_4);
    PROBLEM_FACTORY_REGISTER_CLASS(problem_5);
    PROBLEM_FACTORY_REGISTER_CLASS(problem_6);
    PROBLEM_FACTORY_REGISTER_CLASS(problem_7);
    PROBLEM_FACTORY_REGISTER_CLASS(problem_8);
    PROBLEM_FACTORY_REGISTER_CLASS(problem_9);
    PROBLEM_FACTORY_REGISTER_CLASS(problem_10);
    PROBLEM_FACTORY_REGISTER_CLASS(problem_11);
    PROBLEM_FACTORY_REGISTER_CLASS(problem_12);
    PROBLEM_FACTORY_REGISTER_CLASS(problem_13);
    PROBLEM_FACTORY_REGISTER_CLASS(problem_14);
    PROBLEM_FACTORY_REGISTER_CLASS(problem_15);
    PROBLEM_FACTORY_REGISTER_CLASS(problem_16);
    PROBLEM_FACTORY_REGISTER_CLASS(problem_17);
    PROBLEM_FACTORY_REGISTER_CLASS(problem_18);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_19);
    PROBLEM_FACTORY_REGISTER_CLASS(problem_20);
    PROBLEM_FACTORY_REGISTER_CLASS(problem_21);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_22);
    PROBLEM_FACTORY_REGISTER_CLASS(problem_23);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_24);
    PROBLEM_FACTORY_REGISTER_CLASS(problem_25);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_26);
    PROBLEM_FACTORY_REGISTER_CLASS(problem_27);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_28);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_29);
    PROBLEM_FACTORY_REGISTER_CLASS(problem_30);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_31);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_32);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_33);
    PROBLEM_FACTORY_REGISTER_CLASS(problem_34);
    PROBLEM_FACTORY_REGISTER_CLASS(problem_35);
    PROBLEM_FACTORY_REGISTER_CLASS(problem_36);
    PROBLEM_FACTORY_REGISTER_CLASS(problem_37);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_38);
    PROBLEM_FACTORY_REGISTER_CLASS(problem_39);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_40);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_41);
    PROBLEM_FACTORY_REGISTER_CLASS(problem_42);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_43);
    PROBLEM_FACTORY_REGISTER_CLASS(problem_44);
    PROBLEM_FACTORY_REGISTER_CLASS(problem_45);
    PROBLEM_FACTORY_REGISTER_CLASS(problem_46);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_47);
    PROBLEM_FACTORY_REGISTER_CLASS(problem_48);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_49);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_50);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_51);
    PROBLEM_FACTORY_REGISTER_CLASS(problem_52);
    PROBLEM_FACTORY_REGISTER_CLASS(problem_53);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_54);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_55);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_56);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_57);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_58);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_59);
    PROBLEM_FACTORY_REGISTER_CLASS(problem_60);
    PROBLEM_FACTORY_REGISTER_CLASS(problem_61);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_62);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_63);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_64);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_65);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_66);
    PROBLEM_FACTORY_REGISTER_CLASS(problem_67);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_68);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_69);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_70);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_71);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_72);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_73);
    PROBLEM_FACTORY_REGISTER_CLASS(problem_74);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_75);
    PROBLEM_FACTORY_REGISTER_CLASS(problem_76);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_77);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_78);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_79);
    PROBLEM_FACTORY_REGISTER_CLASS(problem_80);
    PROBLEM_FACTORY_REGISTER_CLASS(problem_81);
    PROBLEM_FACTORY_REGISTER_CLASS(problem_82);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_83);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_84);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_85);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_86);
    PROBLEM_FACTORY_REGISTER_CLASS(problem_87);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_88);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_89);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_90);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_91);
    PROBLEM_FACTORY_REGISTER_CLASS(problem_92);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_93);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_94);
    PROBLEM_FACTORY_REGISTER_CLASS(problem_95);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_96);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_97);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_98);
    PROBLEM_FACTORY_REGISTER_CLASS(problem_99);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_100);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_101);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_102);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_103);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_104);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_105);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_106);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_107);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_108);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_109);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_110);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_111);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_112);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_113);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_114);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_115);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_116);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_117);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_118);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_119);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_120);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_121);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_122);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_123);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_124);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_125);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_126);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_127);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_128);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_129);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_130);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_131);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_132);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_133);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_134);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_135);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_136);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_137);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_138);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_139);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_140);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_141);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_142);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_143);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_144);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_145);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_146);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_147);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_148);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_149);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_150);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_151);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_152);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_153);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_154);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_155);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_156);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_157);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_158);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_159);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_160);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_161);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_162);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_163);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_164);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_165);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_166);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_167);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_168);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_169);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_170);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_171);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_172);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_173);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_174);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_175);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_176);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_177);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_178);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_179);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_180);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_181);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_182);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_183);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_184);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_185);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_186);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_187);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_188);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_189);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_190);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_191);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_192);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_193);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_194);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_195);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_196);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_197);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_198);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_199);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_200);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_201);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_202);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_203);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_204);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_205);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_206);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_207);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_208);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_209);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_210);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_211);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_212);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_213);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_214);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_215);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_216);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_217);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_218);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_219);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_220);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_221);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_222);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_223);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_224);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_225);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_226);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_227);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_228);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_229);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_230);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_231);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_232);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_233);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_234);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_235);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_236);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_237);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_238);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_239);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_240);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_241);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_242);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_243);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_244);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_245);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_246);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_247);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_248);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_249);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_250);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_251);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_252);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_253);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_254);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_255);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_256);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_257);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_258);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_259);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_260);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_261);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_262);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_263);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_264);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_265);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_266);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_267);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_268);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_269);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_270);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_271);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_272);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_273);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_274);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_275);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_276);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_277);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_278);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_279);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_280);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_281);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_282);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_283);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_284);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_285);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_286);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_287);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_288);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_289);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_290);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_291);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_292);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_293);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_294);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_295);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_296);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_297);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_298);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_299);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_300);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_301);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_302);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_303);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_304);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_305);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_306);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_307);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_308);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_309);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_310);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_311);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_312);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_313);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_314);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_315);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_316);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_317);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_318);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_319);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_320);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_321);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_322);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_323);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_324);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_325);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_326);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_327);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_328);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_329);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_330);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_331);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_332);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_333);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_334);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_335);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_336);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_337);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_338);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_339);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_340);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_341);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_342);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_343);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_344);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_345);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_346);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_347);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_348);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_349);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_350);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_351);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_352);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_353);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_354);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_355);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_356);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_357);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_358);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_359);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_360);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_361);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_362);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_363);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_364);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_365);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_366);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_367);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_368);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_369);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_370);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_371);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_372);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_373);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_374);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_375);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_376);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_377);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_378);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_379);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_380);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_381);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_382);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_383);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_384);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_385);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_386);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_387);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_388);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_389);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_390);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_391);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_392);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_393);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_394);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_395);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_396);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_397);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_398);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_399);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_400);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_401);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_402);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_403);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_404);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_405);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_406);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_407);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_408);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_409);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_410);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_411);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_412);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_413);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_414);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_415);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_416);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_417);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_418);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_419);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_420);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_421);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_422);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_423);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_424);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_425);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_426);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_427);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_428);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_429);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_430);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_431);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_432);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_433);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_434);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_435);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_436);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_437);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_438);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_439);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_440);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_441);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_442);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_443);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_444);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_445);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_446);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_447);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_448);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_449);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_450);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_451);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_452);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_453);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_454);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_455);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_456);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_457);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_458);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_459);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_460);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_461);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_462);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_463);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_464);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_465);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_466);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_467);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_468);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_469);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_470);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_471);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_472);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_473);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_474);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_475);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_476);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_477);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_478);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_479);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_480);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_481);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_482);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_483);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_484);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_485);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_486);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_487);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_488);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_489);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_490);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_491);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_492);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_493);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_494);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_495);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_496);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_497);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_498);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_499);
    //PROBLEM_FACTORY_REGISTER_CLASS(problem_500);
    
#else
    
    PROBLEM_FACTORY_REGISTER_CLASS(problem_29);
    PROBLEM_FACTORY_REGISTER_CLASS(problem_60);
    
#endif
}

int main(int, char**)
{
    registerProblems();
    
    cout << endl << "Project Euler - Pat Sluth" << endl << "Starting..." << endl << endl;
    
    cout << "************************************************************" << endl;
    cout << "Options" << endl;
    cout << "[#]:                   run problem #" << endl;
    cout << "[a | all]:             run all problems" << endl;
    cout << "[?]:                   list problems" << endl;
    cout << "[any other key]:       quit" << endl;
    cout << "************************************************************" << endl;
    
    while (true) {
        
        cout << endl << "Enter Option:";
        string rawInput;
        cin >> rawInput;
        
        uint64_t option;
        
        if (sscanf(rawInput.c_str(), "%llu" , &option) == 1) { // number
            
            stringstream problemClassName;
            problemClassName << "problem_" << option;
            
            problem_base *problem = (PROBLEM_FACTORY_INSTANTIATE_CLASS(problemClassName.str()));
            
            if (problem != NULL){
                problem->run();
            } else {
                cout << problemClassName.str() << " does not exist!" << endl;
            }
            
        } else { // not a number
            
            if (rawInput.compare("a") == 0 || rawInput.compare("A") == 0 ||
                rawInput.compare("all") == 0 || rawInput.compare("ALL") == 0) { // run all
                
                for (uint64_t i = 0; i < p_factory.m_classes.size(); i++) {
                    
                    stringstream problemClassName;
                    problemClassName << "problem_" << (i + 1);
                    
                    problem_base *problem = (PROBLEM_FACTORY_INSTANTIATE_CLASS(problemClassName.str()));
                    
                    if (problem != NULL){
                        problem->run();
                    }
                    
                }
                
            } else if (rawInput.compare("?") == 0) {
                
                cout << endl << "Problem List" << endl;
                cout <<  "------------" << endl;
                for (auto problem : p_factory.m_classes) {
                    cout << problem.first << endl;
                }
                
            } else {
                break;
            }
            
        }
        
    }
    
    cout << endl << "Goodbye" << endl;
    
    return EXIT_SUCCESS;
}




