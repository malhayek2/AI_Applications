#
#
#
our $aps =
[
 {
   name => 'Manual',
   key  => 'M',
   header => 'aiSampleManual.h',
   cpp    => ['aiSampleManual.cpp'],
   constructor => 'ai::Jetan::Manual(opts)',
 },
 {
   name => 'Random',
   key  => 'r',
   header => 'aiSampleRandom.h',
   cpp    => ['aiSampleRandom.cpp'],
   constructor => 'ai::Jetan::Random(opts)',
 },
   {
    name => 'MinMax',
    key  => 'x',
    header => 'aiSampleMinimax.h',
    cpp    => ['aiSampleMinimax.cpp'],
    constructor => 'ai::Jetan::Minimax(opts)',
   },
{   
   name => 'AlphaBeta',
   key  => 'a',
   header => 'aiAlphaBeta.h',
   cpp    => ['aiAlphaBeta.cpp'],
   constructor => 'ai::Jetan::AlphaBeta(opts)',
 },
 # {   
 #   name => 'Mosph',
 #   key  => 'p',
 #   header => 'aiMosph.h',
 #   cpp    => ['aiMosph.cpp'],
 #   constructor => 'ai::Jetan::Mosph(opts)',
 # },
 ];

1;
