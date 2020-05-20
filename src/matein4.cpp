
#include <string>
struct Puzzle{
	std::string fen;
	std::string solution;
};
const Puzzle PUZZLES[462]={
Puzzle{
	"r5rk/2p1Nppp/3p3P/pp2p1P1/4P3/2qnPQK1/8/R6R w - - 1 0",
	"1. hxg7+ Rxg7 2. Rxh7+ Rxh7 3. Qf6+ Rg7 4. Rh1# "
},
Puzzle{
	"1r2k1r1/pbppnp1p/1b3P2/8/Q7/B1PB1q2/P4PPP/3R2K1 w - - 1 0",
	"1. Qxd7+ Kxd7 2. Bf5+ Ke8 3. Bd7+ Kf8 4. Bxe7#"
},
Puzzle{
	"Q7/p1p1q1pk/3p2rp/4n3/3bP3/7b/PP3PPK/R1B2R2 b - - 0 1",
	"1... Bxg2 2. Qh8+ Kxh8 3. Bg5 Qxg5 4. Rfe1 Nf3# "
},
Puzzle{
	"r1bqr3/ppp1B1kp/1b4p1/n2B4/3PQ1P1/2P5/P4P2/RN4K1 w - - 1 0",
	"1. Qe5+ Kh6 2. g5+ Kh5 3. Bf3+ Bg4 4. Qh2# "
},
Puzzle{
	"r1b3kr/3pR1p1/ppq4p/5P2/4Q3/B7/P5PP/5RK1 w - - 1 0",
	"1. Rxg7+ Kxg7 2. Qe7+ Kg8 3. Qf8+ Kh7 4. Qf7# "
},
Puzzle{
	"2k4r/1r1q2pp/QBp2p2/1p6/8/8/P4PPP/2R3K1 w - - 1 0",
	"1. Qa8+ Rb8 2. Rxc6+ Qc7 3. Rxc7+ Kd8 4. Qxb8# "
},
Puzzle{
	"2r1r3/p3P1k1/1p1pR1Pp/n2q1P2/8/2p4P/P4Q2/1B3RK1 w - - 1 0",
	"1. f6+ Kh8 2. g7+ Kg8 3. f7+ Kxg7 4. Qf6# "
},
Puzzle{
	"r1bk3r/pppq1ppp/5n2/4N1N1/2Bp4/Bn6/P4PPP/4R1K1 w - - 1 0",
	"1. Nexf7+ Qxf7 2. Nxf7+ Kd7 3. Bb5+ c6 4. Re7# "
},
Puzzle{
	"6kr/pp2r2p/n1p1PB1Q/2q5/2B4P/2N3p1/PPP3P1/7K w - - 1 0",
	"1. Qg7+ Rxg7 2. e7+ Rf7 3. e8=Q+ Qf8 4. Bxf7# "
},
Puzzle{
	"r3k3/pbpqb1r1/1p2Q1p1/3pP1B1/3P4/3B4/PPP4P/5RK1 w - - 1 0",
	"1. Bxg6+ Rxg6 2. Qxg6+ Kd8 3. Rf8+ Qe8 4. Qxe8# "
},
Puzzle{
	"rnb3kr/ppp4p/3b3B/3Pp2n/2BP4/4KRp1/PPP3q1/RN1Q4 w - - 1 0",
	"1. Rf8+ Bxf8 2. d6+ Qd5 3. Bxd5+ Be6 4. Bxe6#"
},
Puzzle{
	"4r3/p4pkp/q7/3Bbb2/P2P1ppP/2N3n1/1PP2KPR/R1BQ4 b - - 0 1",
	"1... Qf1+ 2. Qxf1 Bxd4+ 3. Be3 Rxe3 4. Bxf7 Re2#"
},
Puzzle{
	"2r2b2/p2q1P1p/3p2k1/4pNP1/4P1RQ/7K/2pr4/5R2 w - - 1 0",
	"1. Qxh7+ Kxh7 2. g6+ Kh8 3. Rh4+ Bh6 4. Rxh6#"
},
Puzzle{
	"rnbk2r1/ppp2Q1p/8/1B1Pp1q1/8/2N3B1/PPP3P1/R5K1 w - - 1 0",
	"1. Qxg8+ Ke7 2. Qxg5+ Kd6 3. Ne4+ Kxd5 4. Qxe5# "
},
Puzzle{
	"r1bnk2r/pppp1ppp/1b4q1/4P3/2B1N3/Q1Pp1N2/P4PPP/R3R1K1 w - - 1 0",
	"1. Nf6+ gxf6 2. exf6+ Qe4 3. Rxe4+ Ne6 4. Qe7#"
},
Puzzle{
	"8/6pk/3pp2p/4p1nP/1P2P3/3P1rP1/4qPK1/2QN3R b - - 0 1",
	"1... Rxg3+ 2. Kxg3 Qf3+ 3. Kh4 Qxh1+ 4. Kg3 Qh3# "
},
Puzzle{
	"6rk/7p/pp3b2/2pbqP2/5Q2/5R1P/P6P/2B2R1K b - - 0 1",
	"1... Qe2 2. Rg1 Bxf3+ 3. Qxf3 Qxf3+ 4. Rg2 Qxg2# "
},
Puzzle{
	"r2r4/p1p2p1p/n5k1/1p5N/2p2R2/5N2/P1K3PP/5R2 w - - 1 0",
	"1. Rf6+ Kxh5 2. g4+ Kxg4 3. Rg1+ Kh5 4. Rg5# "
},
Puzzle{
	"r1qbr2k/1p2n1pp/3B1n2/2P1Np2/p4N2/PQ4P1/1P3P1P/3RR1K1 w - - 1 0",
	"1. Nf7+ Kg8 2. Nh6+ Kh8 3. Qg8+ Nexg8 4. Nf7# "
},
Puzzle{
	"k1K5/7r/8/4B3/1RP5/8/8/8 w - - 1 0",
	"1. Rb8+ Ka7 2. Bd4+ Ka6 3. Ra8+ Ra7 4. Rxa7# "
},
Puzzle{
	"2q2r2/5rk1/4pNpp/p2pPn2/P1pP2QP/2P2R2/2B3P1/6K1 w - - 1 0",
	"1. Qxg6+ Kh8 2. Bxf5 exf5 3. Qxh6+ Rh7 4. Qxh7# "
},
Puzzle{
	"qr6/1b1p1krQ/p2Pp1p1/4PP2/1p1B1n2/3B4/PP3K1P/2R2R2 w - - 1 0",
	"1. fxg6+ Kf8 2. Qh8+ Rg8 3. Qf6+ Ke8 4. Qe7#"
},
Puzzle{
	"r6k/pppb1B2/6Q1/8/3P4/2P1q3/PKP3PP/7R w - - 1 0",
	"1. Qf6+ Kh7 2. Bg6+ Kg8 3. Qf7+ Kh8 4. Qh7# "
},
Puzzle{
	"rnb3kr/ppp2ppp/1b6/3q4/3pN3/Q4N2/PPP2KPP/R1B1R3 w - - 1 0",
	"1. Nf6+ gxf6 2. Qf8+ Kxf8 3. Bh6+ Kg8 4. Re8# "
},
Puzzle{
	"3q1rk1/4bp1p/1n2P2Q/1p1p1p2/6r1/Pp2R2N/1B1P2PP/7K w - - 1 0",
	"1. Ng5 Rxg5 2. Rh3 Re8 3. Qxh7+ Kf8 4. Qxf7# "
},
Puzzle{
	"3r1r1k/q2n3p/b1p2ppQ/p1n1p3/Pp2P3/1B1PBR2/1PPN2PP/R5K1 w - - 1 0",
	"1. Qxh7+ Kxh7 2. Rh3+ Kg7 3. Bh6+ Kh7 4. Bxf8# "
},
Puzzle{
	"1rb2r1k/pp1p2pp/5n1N/8/P7/1Q6/1PP3PP/4R2K w - - 1 0",
	"1. Re8 g6 2. Qf7 Ng8 3. Qxg8+ Rxg8 4. Rxg8# "
},
Puzzle{
	"5rbk/2pq3p/5PQR/p7/3p3R/1P4N1/P5PP/6K1 w - - 1 0",
	"1. Nf5 Rf7 2. Rg4 Qe8 3. Qg7+ Rxg7 4. fxg7# "
},
Puzzle{
	"r2q1rk1/ppp1n1p1/1b1p1p2/1B1N2BQ/3pP3/2P3P1/PP3P2/R5K1 w - - 1 0",
	"1. Bc4 Nxd5 2. Bxd5+ Rf7 3. Qxf7+ Kh7 4. Qh5# "
},
Puzzle{
	"r2q3r/ppp5/2n4p/4Pbk1/2BP1Npb/P2QB3/1PP3P1/R5K1 w - - 1 0",
	"1. Qxf5+ Kxf5 2. Bd3+ Kg5 3. Ne6+ Kh5 4. Ng7# "
},
Puzzle{
	"1rb3k1/ppN2R1p/2n1P1p1/6p1/6B1/8/PPP3PP/6K1 w - - 1 0",
	"1. Nd5 Bxe6 2. Bxe6 Kh8 3. Nf6 Ne5 4. Rxh7# "
},
Puzzle{
	"3k1r2/2pb4/2p3P1/2Np1p2/1P6/4nN1R/2P1q3/Q5K1 w - - 1 0",
	"1. Nb7+ Ke7 2. Qg7+ Ke8 3. Qe5+ Be6 4. Qxe6# "
},
Puzzle{
	"2k5/p1p1q3/2P3p1/3QP3/7p/7P/1PK3P1/8 w - - 1 0",
	"1. Qg8+ Qd8 2. Qe6+ Kb8 3. Qb3+ Kc8 4. Qb7#"
},
Puzzle{
	"2k4r/ppp2p2/2b2B2/7p/6pP/2P1q1bP/PP3N2/R4QK1 b - - 0 1",
	"1... Bh2+ 2. Kxh2 Qf4+ 3. Kg1 Qg3+ 4. Qg2 Qxg2#"
},
Puzzle{
	"rnbq1rk1/pp2bp1p/4p1p1/2pp2Nn/5P1P/1P1BP3/PBPP2P1/RN1QK2R w - - 1 0",
	"1. Qxh5 Bxg5 2. Qxh7+ Kxh7 3. hxg5+ Kg8 4. Rh8# "
},
Puzzle{
	"2r2r2/7k/5pRp/5q2/3p1P2/6QP/P2B1P1K/6R1 w - - 1 0",
	"1. Rxh6+ Kxh6 2. Qh4+ Qh5 3. f5+ Kh7 4. Qxh5# "
},
Puzzle{
	"5r2/pq4k1/1pp1Qn2/2bp1PB1/3R1R2/2P3P1/P6P/6K1 w - - 1 0",
	"1. Bxf6+ Rxf6 2. Rg4+ Kh7 3. Qg8+ Kh6 4. Rh4# "
},
Puzzle{
	"3nbr2/4q2p/r3pRpk/p2pQRN1/1ppP2p1/2P5/PPB4P/6K1 w - - 1 0",
	"1. Nf7+ Rxf7 2. Rh5+ Kg7 3. Rxg6+ Kf8 4. Qh8# "
},
Puzzle{
	"2rr1k2/5pp1/p2bp3/1p1B4/1PnP2Pq/P1B2P2/2Q1N1P1/R3R1K1 b - - 0 1",
	"1... Bh2+ 2. Kh1 Bg3+ 3. Kg1 Qh2+ 4. Kf1 Ne3# "
},
Puzzle{
	"5r1k/3q3p/p1pP4/2p2pQ1/r1P3R1/3P4/6PP/1R4K1 w - - 1 0",
	"1. Qf6+ Rxf6 2. Rb8+ Qe8 3. Rxe8+ Rf8 4. Rxf8# "
},
Puzzle{
	"r1b2r2/p2p1pk1/1qp1pN1p/3nP1p1/2B4Q/3R4/PPP2PPP/2K4R w - - 1 0",
	"1. Qxh6+ Kxh6 2. Rh3+ Kg6 3. Bd3+ Kg7 4. Rh7# "
},
Puzzle{
	"8/k2r4/p7/2b1Bp2/P3p3/qp4R1/4QP2/1K6 b - - 0 1",
	"1... Rd1+ 2. Qxd1 Qa2+ 3. Kc1 Ba3+ 4. Bb2 Qxb2# "
},
Puzzle{
	"rnb2b1r/ppp1n1kp/3p1q2/7Q/4PB2/2N5/PPP3PP/R4RK1 w - - 1 0",
	"1. Bh6+ Kg8 2. Rxf6 Ng6 3. Qd5+ Be6 4. Qxe6# "
},
Puzzle{
	"r3r3/3R1Qp1/pqb1p2k/1p4N1/8/4P3/Pb3PPP/2R3K1 w - - 1 0",
	"1. g4 g6 2. h4 Rh8 3. Qh7+ Rxh7 4. Rxh7# "
},
Puzzle{
	"r3k2r/pp3p2/2pQ1Pnp/2P1nqp1/8/1B6/PP3PPP/3RR1K1 w - - 1 0",
	"1. Rxe5+ Qe6 2. Rxe6+ fxe6 3. Qxe6+ Kf8 4. Qf7# "
},
Puzzle{
	"3rkq1r/1pQ2p1p/p3bPp1/3pR3/8/8/PPP2PP1/1K1R4 w - - 1 0",
	"1. Rdxd5 Rxd5 2. Rxd5 Qd6 3. Qxd6 Bxd5 4. Qe7#"
},
Puzzle{
	"r2qrk2/p5b1/2b1p1Q1/1p1pP3/2p1nB2/2P1P3/PP3P2/2KR3R w - - 1 0",
	"1. Rh8+ Bxh8 2. Bh6+ Ke7 3. Qh7+ Bg7 4. Qxg7#"
},
Puzzle{
	"4b3/pkb5/1pp1Bp2/4pPp1/PP2P2r/2PQBq2/8/2KR4 w - - 1 0",
	"1. Qa6+ Ka8 2. Rd8+ Bb8 3. Rxb8+ Kxb8 4. Qc8#  "
},
Puzzle{
	"2r3k1/4p1nR/p3p1p1/4N3/1p2Q3/1P6/P1Pq4/1K6 w - - 1 0",
	"1. Rxg7+ Kh8 2. Rh7+ Kxh7 3. Qxg6+ Kh8 4. Nf7#"
},
Puzzle{
	"r1r3k1/pp1q1p1p/4nBpQ/3pP3/1b5P/3B4/P1P3P1/R2K3R w - - 1 0",
	"1. h5 Bc3 2. Qxh7+ Kxh7 3. hxg6+ Kg8 4. Rh8# "
},
Puzzle{
	"R7/8/2p4k/3pqr1p/6pK/3P4/P5B1/6Q1 b - - 0 1",
	"1... Qf6+ 2. Kg3 Rf3+ 3. Bxf3 Qxf3+ 4. Kh4 Qh3# "
},
Puzzle{
	"rnbq1bnr/pp1p1p1p/3pk3/3NP1p1/5p2/5N2/PPP1Q1PP/R1B1KB1R w - - 1 0",
	"1. Nd4+ Kxd5 2. Qb5+ Kxd4 3. c3+ Ke4 4. Bd3#  "
},
Puzzle{
	"4r3/6kp/ppr3P1/3p4/3Pq3/3nBR2/PP4QP/5R1K w - - 1 0",
	"1. Bh6+ Kxh6 2. Qh3+ Kxg6 3. Rg1+ Qg4 4. Rxg4# "
},
Puzzle{
	"8/2Q2pk1/3Pp1p1/1b5p/1p3P1P/1P2PK2/6RP/7q b - - 0 1",
	"1... Qd1+ 2. Re2 Bxe2+ 3. Kg2 Qf1+ 4. Kg3 Qf3# "
},
Puzzle{
	"rnbq1bkr/pp3p1p/2p3pQ/3N2N1/2B2p2/8/PPPP2PP/R1B1R1K1 w - - 1 0",
	"1. Re8 Nd7 2. Rxd8 cxd5 3. Bxd5 f3 4. Bxf7# "
},
Puzzle{
	"r2q2rk/ppp2p1p/3b1pn1/5R1Q/3P4/2P4N/PP4PP/R1B3K1 w - - 1 0",
	"1. Qxh7+ Kxh7 2. Rh5+ Kg7 3. Bh6+ Kh7 4. Bf8# "
},
Puzzle{
	"r4b1r/pppq2pp/2n1b1k1/3n4/2Bp4/5Q2/PPP2PPP/RNB1R1K1 w - - 1 0",
	"1. Rxe6+ Nf6 2. Qe4+ Kh5 3. Be2+ Ng4 4. Qxg4# "
},
Puzzle{
	"rnbq1b1r/ppp1pQ1p/1n1p2p1/4P2k/3P4/8/PPP2PPP/RNB1K2R w - - 1 0",
	"1. Qf4 h6 2. g3 Bg4 3. h3 Qd7 4. hxg4#"
},
Puzzle{
	"r3rk2/5pR1/pp1q1P1p/8/3p3P/P2B4/1P1Q2b1/1K6 w - - 1 0",
	"1. Rg8+ Kxg8 2. Qxg2+ Qg3 3. Qxg3+ Kf8 4. Qg7# "
},
Puzzle{
	"rk6/N4ppp/Qp2q3/3p4/8/8/5PPP/2R3K1 w - - 1 0",
	"1. Rc8+ Qxc8 2. Qxb6+ Qb7 3. Nc6+ Kc8 4. Qd8#"
},
Puzzle{
	"4q1rk/pb2bpnp/2r4Q/1p1p1pP1/4NP2/1P3R2/PBn4P/RB4K1 w - - 1 0",
	"1. Qxh7+ Kxh7 2. Rh3+ Nh5 3. Rxh5+ Kg6 4. Rh6# "
},
Puzzle{
	"r2Nqb1r/pQ1bp1pp/1pn1p3/1k1p4/2p2B2/2P5/PPP2PPP/R3KB1R w - - 1 0",
	"1. a4+ Ka5 2. Nxc6+ Bxc6 3. b4+ cxb3 4. Qa6# "
},
Puzzle{
	"2r3k1/pp3ppp/1qr2n2/3p1Q2/1P6/P2BP2P/5PP1/2R2RK1 w - - 1 0",
	"1. Qxc8+ Rxc8 2. Rxc8+ Qd8 3. Rxd8+ Ne8 4. Rxe8# "
},
Puzzle{
	"r1b1rk2/ppq3p1/2nbpp2/3pN1BQ/2PP4/7R/PP3PPP/R5K1 w - - 1 0",
	"1. Bxf6 gxf6 2. Ng6+ Kg8 3. Qh8+ Kf7 4. Qh7# "
},
Puzzle{
	"3r1bN1/3p1p1p/pp6/5k2/5P2/P7/1P2PPBq/R2R1K2 w - - 1 0",
	"1. Rd5+ Kxf4 2. e3+ Kg4 3. Nf6+ Kh4 4. Rh5#"
},
Puzzle{
	"5rk1/p3R2p/3p2p1/1p1P1P2/2p4q/P1Pn1P2/6P1/R2Q1K1N b - - 0 1",
	"1... Qxh1+ 2. Ke2 Qxg2+ 3. Ke3 Qf2+ 4. Ke4 gxf5# "
},
Puzzle{
	"2bk4/6b1/2pNp3/r1PpP1P1/P1pP1Q2/2rq4/7R/6RK w - - 1 0",
	"1. Rh8+ Bxh8 2. Qf8+ Kd7 3. Qxc8+ Ke7 4. Qe8#"
},
Puzzle{
	"4r2k/pp2q2b/2p2p1Q/4rP2/P7/1B5P/1P2R1R1/7K w - - 1 0",
	"1. Rxe5 fxe5 2. f6 Qd7 3. Qg7+ Qxg7 4. fxg7# "
},
Puzzle{
	"7k/6p1/2p3pp/1p4qn/4r3/2Pr2P1/PP2BP1K/1Q3R2 b - - 0 1",
	"1... Rh4+ 2. gxh4 Rh3+ 3. Kxh3 Nf4+ 4. Kh2 Qg2#"
},
Puzzle{
	"2r2rk1/1b3pp1/4p3/p3P1Q1/1pqP1R2/2P5/PP1B1K1P/R7 w - - 1 0",
	"1. Qxg7+ Kxg7 2. Rg1+ Bg2 3. Rxg2+ Kh7 4. Rh4#"
},
Puzzle{
	"2q2rk1/4r1bp/bpQp2p1/p2Pp3/P3P2P/1NP1B1K1/1P6/R2R4 b - - 0 1",
	"1... Rf3+ 2. Kxf3 Qh3+ 3. Kf2 Qh2+ 4. Kf3 Be2# "
},
Puzzle{
	"3kn3/p1p2Rp1/1p2q3/7p/7P/5QP1/P6K/8 w - - 1 0",
	"1. Qa8+ Qc8 2. Qd5+ Nd6 3. Qg5+ Ke8 4. Qe7# "
},
Puzzle{
	"4r3/p1r2p1k/1p2pPpp/2qpP3/3R2P1/1PPQ3R/1P5P/7K w - - 1 0",
	"1. Rxh6+ Kxh6 2. Qh3+ Kg5 3. Qe3+ Kh4 4. Qh6# "
},
Puzzle{
	"6rk/Q2n2rp/5p2/3P4/4P3/2q4P/P5P1/5RRK b - - 0 1",
	"1... Rxg2 2. Qxd7 Qg3 3. Qg7+ Rxg7 4. Rxg2 Qxg2# "
},
Puzzle{
	"8/Q7/5pkp/2n1q3/8/1B5P/5PP1/6K1 w - - 1 0",
	"1. Qf7+ Kf5 2. Qh5+ Ke4 3. Qe2+ Kf4 4. Qg4#"
},
Puzzle{
	"rq3kB1/pp1b1p2/4pB1p/4P3/3P3Q/P1n5/5PPP/R5K1 w - - 1 0",
	"1. Qxh6+ Ke8 2. Bxf7+ Kxf7 3. Qg7+ Ke8 4. Qe7# "
},
Puzzle{
	"3r1k1r/p1q2p2/1pp2N1p/n3RQ2/3P4/2p1PR2/PP4PP/6K1 w - - 1 0",
	"1. Nh7+ Rxh7 2. Qxh7 f5 3. Rexf5+ Ke8 4. Rf8# "
},
Puzzle{
	"r3r1k1/ppp2p1p/1b3Bp1/4P3/3P1n2/2PB1N2/PP6/2KR3R w - - 1 0",
	"1. Rxh7 Kxh7 2. Rh1+ Nh5 3. Rxh5+ Kg8 4. Rh8# "
},
Puzzle{
	"7R/r1p1q1pp/3k4/1p1n1Q2/3N4/8/1PP2PPP/2B3K1 w - - 1 0",
	"1. Rd8+ Qxd8 2. Qe6+ Kc5 3. Nb3+ Kb4 4. Qe4# "
},
Puzzle{
	"3rb1k1/ppq3p1/2p1p1p1/6P1/2Pr3R/1P1Q4/P1B4P/5RK1 w - - 1 0",
	"1. Rh8+ Kxh8 2. Rf8+ Kh7 3. Qh3+ Rh4 4. Qxh4#"
},
Puzzle{
	"3r4/pk3pq1/Nb2p2p/3n4/2QP4/6P1/1P3PBP/5RK1 w - - 1 0",
	"1. Rc1 Bc5 2. Qb5+ Bb6 3. Rc7+ Ka8 4. Qc6# "
},
Puzzle{
	"4r2r/5k2/2p2P1p/p2pP1p1/3P2Q1/6PB/1n5P/6K1 w - - 1 0",
	"1. Qd7+ Re7 2. Qxe7+ Kg6 3. Qg7+ Kh5 4. Qf7# "
},
Puzzle{
	"4b3/k1r1q2p/p3p3/3pQ3/2pN4/1R6/P4PPP/1R4K1 w - - 1 0",
	"1. Nc6+ Bxc6 2. Qd4+ Qc5 3. Qxc5+ Ka8 4. Rb8#"
},
Puzzle{
	"r7/p1n2p1R/qp1p1k2/3Pp3/bPp1P3/2P1BBN1/3Q2K1/8 w - - 1 0",
	"1. Bg5+ Kg6 2. Rh6+ Kg7 3. Bf6+ Kg8 4. Rh8# "
},
Puzzle{
	"r3QnR1/1bk5/pp5q/2b5/2p1P3/P7/1BB4P/3R3K w - - 1 0",
	"1. Be5+ Bd6 2. Rg7+ Nd7 3. Qxd7+ Kb8 4. Qxb7# "
},
Puzzle{
	"r5k1/1p4pp/2p1p2r/p2nRp2/P2P1P1P/1P3qP1/1BQ2P2/R5K1 b - - 0 1",
	"1... Nxf4 2. Qe4 fxe4 3. gxf4 Rxh4 4. Rh5 Qh1# "
},
Puzzle{
	"5k2/p2Q1pp1/1b5p/1p2PB1P/2p2P2/8/PP3qPK/8 w - - 1 0",
	"1. Qd6+ Ke8 2. Bd7+ Kd8 3. Bxb5+ Kc8 4. Ba6# "
},
Puzzle{
	"2br3k/pp3Pp1/1n2p3/1P2N1pr/2P2qP1/8/1BQ2P1P/4R1K1 w - - 1 0",
	"1. Ng6+ Kh7 2. Nf8+ Kh8 3. Qh7+ Rxh7 4. Ng6# "
},
Puzzle{
	"3r4/6kp/1p1r1pN1/5Qq1/6p1/PB4P1/1P3P2/6KR w - - 1 0",
	"1. Rxh7+ Kxh7 2. Nf8+ Kg7 3. Qh7+ Kxf8 4. Qf7# "
},
Puzzle{
	"5r1k/7p/p2b4/1pNp1p1q/3Pr3/2P2bP1/PP1B3Q/R3R1K1 b - - 0 1",
	"1... Qxh2+ 2. Kxh2 Rh4+ 3. Kg1 Bxg3 4. Bf4 Rh1# "
},
Puzzle{
	"5rk1/pR6/3Q4/2pPnp1p/P3p2q/4P1N1/5Pp1/6K1 b - - 0 1",
	"1... Nf3+ 2. Kxg2 Qh2+ 3. Kf1 Qg1+ 4. Ke2 Qe1#"
},
Puzzle{
	"r4r1k/pp4R1/3pN1p1/3P2Qp/1q2Ppn1/8/6PP/5RK1 w - - 1 0",
	"1. Rh7+ Kxh7 2. Qe7+ Rf7 3. Qxf7+ Kh6 4. Qg7# "
},
Puzzle{
	"r7/1p3Q2/2kpr2p/p1p2Rp1/P3Pp2/1P3P2/1B2q1PP/3R3K w - - 1 0",
	"1. Rxc5+ Kb6 2. Qc7+ Ka7 3. Rxa5+ Qa6 4. Bd4# "
},
Puzzle{
	"4r1k1/5pbp/3p2p1/1ppP4/pqP5/R4B2/1PQ3PP/1K6 b - - 0 1",
	"1... Re1+ 2. Bd1 Rxd1+ 3. Ka2 Qxa3+ 4. Kxa3 Ra1# "
},
Puzzle{
	"4k3/R3n2p/4N3/3p1p2/2b2P2/5BP1/4P1K1/2r5 w - - 1 0",
	"1. Bh5+ Ng6 2. Rxh7 Rg1+ 3. Kxg1 Bxe2 4. Bxg6# "
},
Puzzle{
	"1R4Q1/3nr1pp/3p1k2/5Bb1/4P3/2q1B1P1/5P1P/6K1 w - - 1 0",
	"1. Rf8+ Nxf8 2. Qxf8+ Ke5 3. f4+ Bxf4 4. gxf4# "
},
Puzzle{
	"r1b2rk1/1p4qp/p5pQ/2nN1p2/2B2P2/8/PPP3PP/2K1R3 w - - 1 0",
	"1. Ne7+ Kh8 2. Nxg6+ Qxg6 3. Qxf8+ Qg8 4. Qxg8#"
},
Puzzle{
	"2r2rk1/pp3nbp/2p1bq2/2Pp4/1P1P1PP1/P1NB4/1BQK4/7R w - - 1 0",
	"1. Bxh7+ Kh8 2. Bg8+ Qh6 3. Rxh6+ Bxh6 4. Qh7# "
},
Puzzle{
	"r2r4/1p1R3p/5p1k/b1B1Pp2/p4P2/P7/1P5P/1K4R1 w - - 1 0",
	"1. Bf8+ Rxf8 2. Rd3 Be1 3. Rh3+ Bh4 4. Rxh4# "
},
Puzzle{
	"R4rk1/4r1p1/1q2p1Qp/1pb5/1n5R/5NB1/1P3PPP/6K1 w - - 1 0",
	"1. Ng5 Bxf2+ 2. Kh1 Rxa8 3. Qh7+ Kf8 4. Qh8# "
},
Puzzle{
	"8/4k3/1p2p1p1/pP1pPnP1/P1rPq2p/1KP2R1N/8/5Q2 b - - 0 1",
	"1... Nxd4+ 2. Ka3 Rxa4+ 3. Kxa4 Qc2+ 4. Ka3 Qb3#"
},
Puzzle{
	"kb3R2/1p5r/5p2/1P1Q4/p5P1/q7/5P2/4RK2 w - - 1 0",
	"1. Rxb8+ Ka7 2. Qd4+ Kxb8 3. Re8+ Kc7 4. Qd8#  "
},
Puzzle{
	"8/1p5k/5pp1/7p/P3qP1K/2Q3PP/8/8 b - - 0 1",
	"1... g5+ 2. Kxh5 Qe2+ 3. Qf3 Qxf3+ 4. g4 Qxh3# "
},
Puzzle{
	"6k1/pp3ppp/4p3/2P3b1/bPP3P1/3K4/P3Q1q1/1R5R b - - 0 1",
	"1... Qg3+ 2. Ke4 Bc6+ 3. Kd4 Bf6+ 4. Qe5 Bxe5#"
},
Puzzle{
	"r7/2p2p2/3p3k/pR1P1Kb1/3P2pr/B1PB1b2/P4P2/1R6 b - - 0 1",
	"1... g3 2. Bxd6 Bg4+ 3. Ke5 Re8+ 4. Be7 Rxe7#"
},
Puzzle{
	"r1bq3Q/pppnk1p1/2n1p1P1/3pPr2/1b1P4/1NP5/PP3PP1/R1B1K3 w Q - 0 1",
	"1. Bg5+ Rf6 2. Bxf6+ gxf6 3. Qg7+ Ke8 4. Qf7# "
},
Puzzle{
	"2rqrb2/p2nk3/bp2pnQp/4B1p1/3P4/P1N5/1P3PPP/1B1RR1K1 w - - 1 0",
	"1. Nd5+ exd5 2. Bxf6+ Kd6 3. Be5+ Ke7 4. Bd6# "
},
Puzzle{
	"2r1rk2/1p2qp1R/4p1p1/1b1pP1N1/p2P4/nBP1Q3/P4PPP/R5K1 w - - 1 0",
	"1. Rh8+ Kg7 2. Nxe6+ Kxh8 3. Qh6+ Kg8 4. Qg7# "
},
Puzzle{
	"5nk1/2N2p2/2b2Qp1/p3PpNp/2qP3P/6P1/5P1K/8 w - - 1 0",
	"1. e6 Be8 2. Nxe8 Nxe6 3. Qxf7+ Kh8 4. Qh7# "
},
Puzzle{
	"r2Bk2r/pb1n1pQ1/3np3/1p2P3/2p3K1/3p4/PP1b1PPP/R4B1R b - - 0 1",
	"1... f5+ 2. Kg3 Ne4+ 3. Kf3 Nef6+ 4. Kg3 f4# "
},
Puzzle{
	"6k1/6p1/3r1n1p/p4p1n/P1N4P/2N5/Q2RK3/7q b - - 0 1",
	"1... Ng3+ 2. Ke3 Ng4+ 3. Kf4 Nh5+ 4. Kxf5 Qf3#"
},
Puzzle{
	"8/p5Qp/1p2q2B/2p2rp1/2P3Pk/2P2P2/P6P/6K1 w - - 1 0",
	"1. Bxg5+ Rxg5 2. Qxh7+ Qh6 3. Qxh6+ Rh5 4. Qxh5# "
},
Puzzle{
	"rq3rk1/1p1bpp1p/3p2pQ/p2N3n/2BnP1P1/5P2/PPP5/2KR3R w - - 1 0",
	"1. Nxe7+ Kh8 2. Rxh5 Nb3+ 3. axb3 gxh5 4. Qf6#"
},
Puzzle{
	"r2r1n2/pp2bk2/2p1p2p/3q4/3PN1QP/2P3R1/P4PP1/5RK1 w - - 1 0",
	"1. Qg7+ Ke8 2. Qxe7+ Kxe7 3. Rg7+ Ke8 4. Nf6# "
},
Puzzle{
	"1r4k1/3p3R/4p3/2p1P1qp/2P1Q3/1n1B4/6P1/7K w - - 1 0",
	"1. Rh8+ Kf7 2. Qh7+ Qg7 3. Bg6+ Ke7 4. Qxg7#"
},
Puzzle{
	"r2r1k2/pbq2pp1/2p1p1p1/1pP1N1P1/6Q1/P6R/1P3P1P/4R1K1 w - - 1 0",
	"1. Nxg6+ Ke8 2. Rxe6+ fxe6 3. Qxe6+ Qe7 4. Qxe7# "
},
Puzzle{
	"q5k1/1b2R1pp/1p3n2/4BQ2/8/7P/5PPK/4r3 w - - 1 0",
	"1. Rxg7+ Kh8 2. Rxh7+ Kg8 3. Qg6+ Kf8 4. Qf7# "
},
Puzzle{
	"1R6/4r1pk/pp2N2p/4nP2/2p5/2P3P1/P2P1K2/8 w - - 1 0",
	"1. Nf8+ Kg8 2. Ng6+ Re8 3. Rxe8+ Kf7 4. Rf8# "
},
Puzzle{
	"r4rk1/p4pp1/7P/2pp4/3Bn3/8/qPP1QP1P/2KR2R1 w - - 1 0",
	"1. h7+ Kh8 2. Bxg7+ Kxh7 3. Qh5+ Kg8 4. Qh8#"
},
Puzzle{
	"r1r2bk1/p4pBp/1p6/3q1N2/n1P5/4R3/P3QPPP/6K1 w - - 1 0",
	"1. Nh6+ Kxg7 2. Qg4+ Kxh6 3. Rh3+ Qh5 4. Rxh5# "
},
Puzzle{
	"3q1r2/2n5/p4pkp/3PrN1p/1pP2Q2/1P4BP/P4PP1/R5K1 w - - 1 0",
	"1. Qxh6+ Kf7 2. Qxh5+ Kg8 3. Qg6+ Kh8 4. Qg7# "
},
Puzzle{
	"7R/2rr1kp1/p3p3/1p1q1p2/n4P1Q/P4P2/4B2P/6RK w - - 1 0",
	"1. Rxg7+ Kxg7 2. Qh6+ Kf7 3. Qf8+ Kg6 4. Rh6# "
},
Puzzle{
	"r2q4/1p2N2k/1P3Qp1/pBnpp3/4b1P1/8/P6P/5RK1 w - - 1 0",
	"1. Rf3 Qf8 2. Rh3+ Qh6 3. Qf7+ Kh8 4. Rxh6# "
},
Puzzle{
	"rn3k1r/pbpp1Bbp/1p4pN/4P1B1/3n4/2q3Q1/PPP2PPP/2KR3R w - - 1 0",
	"1. Be7+ Kxe7 2. Qg5+ Bf6 3. Qxf6+ Kf8 4. Bxg6#"
},
Puzzle{
	"r1q5/2p2k2/p4Bp1/2Nb1N2/p6Q/7P/nn3PP1/R5K1 w - - 1 0",
	"1. Qh7+ Kxf6 2. Qe7+ Kxf5 3. g4+ Kf4 4. Qe3# "
},
Puzzle{
	"r2r1k2/5pRp/pq2pBn1/1p2P2Q/2p4P/2Pn2P1/PP3Pb1/5RK1 w - - 1 0",
	"1. Rg8+ Kxg8 2. Qh6 Qxf2+ 3. Rxf2 Nxf2 4. Qg7# "
},
Puzzle{
	"6rk/5p1p/5p2/1p2bP2/1P2R2Q/2q1BBPP/5PK1/r7 w - - 1 0",
	"1. Qxh7+ Kxh7 2. Rh4+ Kg7 3. Bh6+ Kh7 4. Bf8#"
},
Puzzle{
	"1qbk2nr/1pNp2Bp/2n1pp2/8/2P1P3/8/Pr3PPP/R2QKB1R w - - 1 0",
	"1. Nxe6+ Ke7 2. Bf8+ Kf7 3. Qh5+ Kxe6 4. Qd5#"
},
Puzzle{
	"5Q1R/3qn1p1/p3p1k1/1pp1PpB1/3r3P/5P2/PPP3K1/8 w - - 1 0",
	"1. Rh6+ gxh6 2. Qf6+ Kh7 3. Qf7+ Kh8 4. Bf6#"
},
Puzzle{
	"6rk/3b3p/p2b1p2/2pPpP2/2P1B3/1P4q1/P2BQ1PR/6K1 w - - 1 0",
	"1. Rxh7+ Kxh7 2. Qh5+ Kg7 3. Bh6+ Kh7 4. Bf8# "
},
Puzzle{
	"5r1k/1p1b1p1p/p2ppb2/5P1B/1q6/1Pr3R1/2PQ2PP/5R1K w - - 1 0",
	"1. Qh6 Rxg3 2. Bg6 Rxg6 3. fxg6 fxg6 4. Qxf8# "
},
Puzzle{
	"2R2bk1/5rr1/p3Q2R/3Ppq2/1p3p2/8/PP1B2PP/7K w - - 1 0",
	"1. Rxf8+ Kxf8 2. Rh8+ Rg8 3. Bxb4+ Kg7 4. Qh6# "
},
Puzzle{
	"3rkb2/pp3R1R/8/2p1P3/3pKB2/6P1/PrP2P2/8 w - - 1 0",
	"1. Bh6 Bxh6 2. e6 Bf8 3. Rh8 Rxc2 4. Rhxf8# "
},
Puzzle{
	"3q3r/r4pk1/pp2pNp1/3bP1Q1/7R/8/PP3PPP/3R2K1 w - - 1 0",
	"1. Ne8+ Kg8 2. Rxh8+ Kxh8 3. Qh6+ Kg8 4. Qg7#"
},
Puzzle{
	"8/3P1pk1/8/1p5p/1N4p1/2P5/3qb1PP/2R1R1K1 b - - 0 1",
	"1... Bf3 2. gxf3 gxf3 3. Re2 Qxe2 4. d8=Q Qg2# "
},
Puzzle{
	"rqr3k1/3bppBp/3p2P1/p7/1n2P3/1p3P2/1PPQ2P1/2KR3R w - - 1 0",
	"1. gxh7+ Kxg7 2. h8=Q+ Rxh8 3. Qg5+ Kf8 4. Rxh8# "
},
Puzzle{
	"2k3rr/p4q1p/N2B4/p3PpQ1/3P2n1/8/2P2PPP/1R4K1 w - - 1 0",
	"1. Nc5 Qc7 2. Qxf5+ Kd8 3. Rb8+ Qxb8 4. Qd7# "
},
Puzzle{
	"3q1r2/2rbnp2/p3pp1k/1p1p2N1/3P2Q1/P3P3/1P3PPP/5RK1 w - - 1 0",
	"1. Qh4+ Kg6 2. Qh7+ Kxg5 3. f4+ Kg4 4. Qh3# "
},
Puzzle{
	"1R2R3/p1r2pk1/3b1pp1/8/2Pr4/4N1P1/P4PK1/8 w - - 1 0",
	"1. Nf5+ gxf5 2. Rg8+ Kh6 3. Rh8+ Kg5 4. Rbg8# "
},
Puzzle{
	"r1bq2k1/pp2n1p1/5r2/2p2pNQ/3p4/3P4/PPP2PBP/R3R1K1 w - - 1 0",
	"1. Rxe7 Rg6 2. Qxg6 Qxe7 3. Qh7+ Kf8 4. Qh8#"
},
Puzzle{
	"6rk/1b6/p5pB/1q2P2Q/4p2P/6R1/PP4PK/3r4 w - - 1 0",
	"1. Bg7+ Kxg7 2. Qxg6+ Kf8 3. Qxg8+ Ke7 4. Rg7# "
},
Puzzle{
	"6r1/p5bk/4N1pp/2B1p3/4Q2N/8/2P2KPP/q7 w - - 1 0",
	"1. Ng5+ hxg5 2. Qxg6+ Kh8 3. Qh5+ Bh6 4. Qxh6# "
},
Puzzle{
	"2rq2k1/3bb2p/n2p2pQ/p2Pp3/2P1N1P1/1P5P/6B1/2B2R1K w - - 1 0",
	"1. Rf7 Kxf7 2. Qxh7+ Ke8 3. Qxg6+ Kf8 4. Bh6# "
},
Puzzle{
	"5rk1/ppp3pp/8/3pQ3/3P2b1/5rPq/PP1P1P2/R1BB1RK1 b - - 0 1",
	"1... Qxf1+ 2. Kxf1 Rxf2+ 3. Kg1 Rf1+ 4. Kg2 R8f2# "
},
Puzzle{
	"r7/5pk1/2p4p/1p1p4/1qnP4/5QPP/2B1RP1K/8 w - - 1 0",
	"1. Qg4+ Kf8 2. Bh7 Ne3 3. Rxe3 Qxd4 4. Qg8# "
},
Puzzle{
	"8/r7/3pNb2/3R3p/1p2p3/pPk5/P1P3PP/1K6 w - - 1 0",
	"1. Rd1 Be5 2. Ng5 d5 3. Rxd5 Bxh2 4. Nxe4#"
},
Puzzle{
	"r1bqkb2/6p1/p1p4p/1p1N4/8/1B3Q2/PP3PPP/3R2K1 w - - 1 0",
	"1. Nc7+ Qxc7 2. Qh5+ g6 3. Qxg6+ Ke7 4. Qf7# "
},
Puzzle{
	"5r1k/p5p1/1p3n1p/1Pp5/2RPp3/P3P2P/2Q3PK/2N1q3 b - d3 0 1",
	"1... Ng4+ 2. hxg4 Rf1 3. Qf2 Qxf2 4. d5 Qh4# "
},
Puzzle{
	"r2r2k1/1q4p1/ppb3p1/2bNp3/P1Q5/1N5R/1P4BP/n6K w - - 1 0",
	"1. Ne7+ Kf8 2. Nxg6+ Ke8 3. Qe6+ Qe7 4. Rh8# "
},
Puzzle{
	"2r1r3/pp1nbN2/4p3/q7/P1pP2nk/2P2P2/1PQ5/R3R1K1 w - - 1 0",
	"1. Re4 Kh5 2. Rxg4 Qf5 3. Qh2+ Bh4 4. Qxh4# "
},
Puzzle{
	"r3r2k/pb1n3p/1p1q1pp1/4p1B1/2BP3Q/2P1R3/P4PPP/4R1K1 w - - 1 0",
	"1. Qxh7+ Kxh7 2. Rh3+ Kg7 3. Bh6+ Kh7 4. Bf8# "
},
Puzzle{
	"r1b2rk1/p3Rp1p/3q2pQ/2pp2B1/3b4/3B4/PPP2PPP/4R1K1 w - - 1 0",
	"1. Qxf8+ Kxf8 2. Bh6+ Kg8 3. Re8+ Qf8 4. Rxf8# "
},
Puzzle{
	"r1b3kn/2p1q1p1/2p2rP1/p2p1p2/4pP2/1PN1P3/PKPPQ3/3R2NR w - - 1 0",
	"1. Rxh8+ Kxh8 2. Qh5+ Kg8 3. Qh7+ Kf8 4. Qh8#"
},
Puzzle{
	"5r1k/2q1r1p1/1npbBpQB/1p1p3P/p2P2R1/P4PP1/1PR2PK1/8 w - - 1 0",
	"1. Bxg7+ Rxg7 2. Qh6+ Rh7 3. Qxf8+ Bxf8 4. Rg8# "
},
Puzzle{
	"8/6R1/p2kp2r/qb5P/3p1N1Q/1p1Pr3/PP6/1K5R w - - 1 0",
	"1. Qe7+ Kc6 2. Rc1+ Bc4 3. Rxc4+ Kb6 4. Qb7# "
},
Puzzle{
	"r5nr/6Rp/p1NNkp2/1p3b2/2p5/5K2/PP2P3/3R4 w - - 1 0",
	"1. Nxf5 Kxf5 2. e4+ Ke6 3. Rgd7 Ne7 4. Rxe7#"
},
Puzzle{
	"2b2k2/2p2r1p/p2pR3/1p3PQ1/3q3N/1P6/2P3PP/5K2 w - - 1 0",
	"1. Ng6+ hxg6 2. Qd8+ Kg7 3. Rxg6+ Kh7 4. Qg8# "
},
Puzzle{
	"1Qb2b1r/1p1k1p1p/3p1p2/3p4/p2NPP2/1R6/q1P3PP/4K2R w K - 0 1",
	"1. Rxb7+ Bxb7 2. Qxb7+ Kd8 3. Nc6+ Ke8 4. Qc8# "
},
Puzzle{
	"3r2k1/3q2p1/1b3p1p/4p3/p1R1P2N/Pr5P/1PQ3P1/5R1K b - - 0 1",
	"1... Rxh3+ 2. gxh3 Qxh3+ 3. Qh2 Qxf1+ 4. Qg1 Qxg1# "
},
Puzzle{
	"3r2k1/pp5p/6p1/2Ppq3/4Nr2/4B2b/PP2P2K/R1Q1R2B b - - 0 1",
	"1... Rf2+ 2. Kxh3 Rh2+ 3. Kg4 h5+ 4. Kf3 dxe4# "
},
Puzzle{
	"1q1N4/3k1BQp/5r2/5p2/3P3P/8/3B1PPb/3n3K w - - 1 0",
	"1. Be6+ Ke8 2. Qd7+ Kf8 3. Bh6+ Rxh6 4. Qf7# "
},
Puzzle{
	"3r1rk1/ppqn3p/1npb1P2/5B2/2P5/2N3B1/PP2Q1PP/R5K1 w - - 1 0",
	"1. Qg4+ Kf7 2. Be6+ Kxf6 3. Bh4+ Ke5 4. Qe4#"
},
Puzzle{
	"2r1k3/2P3R1/3P2K1/6N1/8/8/8/3r4 w - - 1 0",
	"1. Re7+ Kf8 2. Nh7+ Kg8 3. Nf6+ Kf8 4. Rf7# "
},
Puzzle{
	"r1b2k1r/pppp4/1bP2qp1/5pp1/4pP2/1BP5/PBP3PP/R2Q1R1K b - - 0 1",
	"1... Rxh2+ 2. Kxh2 Qh8+ 3. Qh5 Qxh5+ 4. Kg3 Qh4# "
},
Puzzle{
	"rr2k3/5p2/p1bppPpQ/2p1n1P1/1q2PB2/2N4R/PP4BP/6K1 w - - 1 0",
	"1. Qf8+ Kd7 2. Qe7+ Kc8 3. Rh8+ Be8 4. Rxe8# "
},
Puzzle{
	"2r1rk2/p1q3pQ/4p3/1pppP1N1/7p/4P2P/PP3P2/1K4R1 w - - 1 0",
	"1. Nxe6+ Ke7 2. Rxg7+ Kxe6 3. Qg6+ Kxe5 4. f4# "
},
Puzzle{
	"r2r2k1/1p3pb1/q2p2p1/3PnN1R/p1P1p3/N6Q/PP5P/1K4R1 w - - 1 0",
	"1. Rh7 Bf6 2. Qh6 Nd3 3. Rg7+ Bxg7 4. Qxg7# "
},
Puzzle{
	"6k1/6pp/p3p3/1pb5/5P2/PQ3RKP/1P3P1B/3r3q b - - 0 1",
	"1... Rg1+ 2. Bxg1 Qxg1+ 3. Kh4 Be7+ 4. Kh5 Qg6# "
},
Puzzle{
	"5k2/6r1/p7/2p1P3/1p2Q3/8/1q4PP/3R2K1 w - - 1 0",
	"1. Rd8+ Ke7 2. Qh4+ Rg5 3. Qxg5+ Ke6 4. Qf6# "
},
Puzzle{
	"k1b4r/1p6/pR3p2/P1Qp2p1/2pp4/6PP/2P2qBK/8 w - - 1 0",
	"1. Rxa6+ bxa6 2. Qxd5+ Kb8 3. Qd6+ Ka7 4. Qb6# "
},
Puzzle{
	"4R3/2p2kpQ/3p3p/p2r2q1/8/1Pr2P2/P1P3PP/4R1K1 w - - 1 0",
	"1. Rf8+ Kxf8 2. Qh8+ Kf7 3. Qe8+ Kf6 4. Qe6# "
},
Puzzle{
	"r1b4k/1p4qp/p7/4p2P/2B5/6Q1/PPP3P1/2K2R2 w - - 1 0",
	"1. Rf8+ Qxf8 2. Qxe5+ Qg7 3. Qe8+ Qg8 4. Qxg8# "
},
Puzzle{
	"r1b2n2/2q3rk/p3p2n/1p3p1P/4N3/PN1B1P2/1PPQ4/2K3R1 w - - 1 0",
	"1. Nf6+ Kh8 2. Qxh6+ Nh7 3. Qxh7+ Rxh7 4. Rg8# "
},
Puzzle{
	"r2qr1k1/1p3pP1/p2p1np1/2pPp1B1/2PnP1b1/2N2p2/PP1Q4/2KR1BNR w - - 1 0",
	"1. Bxf6 Bh5 2. Qh6 Nb3+ 3. axb3 Qxf6 4. Qh8# "
},
Puzzle{
	"5k2/ppqrRB2/3r1p2/2p2p2/7P/P1PP2P1/1P2QP2/6K1 w - - 1 0",
	"1. Re8+ Kxf7 2. Qh5+ Kg7 3. Rh8 Rxd3 4. Qh7# "
},
Puzzle{
	"4n3/pbq2rk1/1p3pN1/8/2p2Q2/Pn4N1/B4PP1/4R1K1 w - - 1 0",
	"1. Nf5+ Kxg6 2. Qh6+ Kxf5 3. Qh5+ Kf4 4. g3# "
},
Puzzle{
	"r4k2/PR6/1b6/4p1Np/2B2p2/2p5/2K5/8 w - - 1 0",
	"1. Nh7+ Ke8 2. Nf6+ Kd8 3. Rd7+ Kc8 4. Ba6# "
},
Puzzle{
	"8/5R1p/4p1p1/3pN1k1/1rnP4/p3P3/P1K2PPP/8 w - - 1 0",
	"1. f4+ Kh6 2. Ng4+ Kh5 3. Nf6+ Kh6 4. Rxh7# "
},
Puzzle{
	"br1qr1k1/b1pnnp2/p2p2p1/P4PB1/3NP2Q/2P3N1/B5PP/R3R1K1 w - - 1 0",
	"1. Bxf7+ Kf8 2. Qh8+ Kxf7 3. Qh7+ Kf8 4. Bh6# "
},
Puzzle{
	"6k1/ppR3pp/8/3Np3/1Q4bP/6P1/PP2qbK1/8 w - - 1 0",
	"1. Rxg7+ Kxg7 2. Qe7+ Kg6 3. Qf6+ Kh5 4. Qg5# "
},
Puzzle{
	"r3r3/1q2Pk1p/pn1Q2p1/1p3pB1/8/5N2/P5PP/2R1b2K w - - 1 0",
	"1. Ne5+ Kg7 2. Qf6+ Kg8 3. Qf7+ Kh8 4. Bf6# "
},
Puzzle{
	"1r3rk1/1nqb2n1/6R1/1p1Pp3/1Pp3p1/2P4P/2B2QP1/2B2RK1 w - - 1 0",
	"1. Rxg7+ Kxg7 2. Bh6+ Kxh6 3. Qh4+ Kg7 4. Qh7# "
},
Puzzle{
	"n2q1r1k/4bp1p/4p3/4P1p1/2pPNQ2/2p4R/5PPP/2B3K1 w - - 1 0",
	"1. Nf6 Bxf6 2. Qe4 h5 3. Rxh5+ Kg8 4. Qh7# "
},
Puzzle{
	"3r2k1/6p1/3Np2p/2P1P3/1p2Q1Pb/1P3R1P/1qr5/5RK1 w - - 1 0",
	"1. Rf8+ Rxf8 2. Rxf8+ Kxf8 3. Qa8+ Ke7 4. Qe8# "
},
Puzzle{
	"1qr2bk1/pb3pp1/1pn3np/3N2NQ/8/P7/BP3PPP/2B1R1K1 w - - 1 0",
	"1. Nf6+ gxf6 2. Qxg6+ Bg7 3. Bxf7+ Kf8 4. Nh7# "
},
Puzzle{
	"1r4k1/7R/p2p4/P5q1/1P2B3/5Pb1/2Q3K1/8 w - - 1 0",
	"1. Bd5+ Kf8 2. Rf7+ Ke8 3. Qc6+ Kd8 4. Qd7# "
},
Puzzle{
	"3q4/8/r1b4Q/2P2kp1/p2p4/P7/1P5P/4R1K1 w - - 1 0",
	"1. Qe6+ Kf4 2. h3 Bd7 3. Qe5+ Kf3 4. Rf1# "
},
Puzzle{
	"6k1/p2R1p1p/5bp1/8/Pn2R1K1/1r6/7P/8 b - - 0 1",
	"1... h5+ 2. Kf4 g5+ 3. Kf5 Rf3+ 4. Rf4 Rxf4# "
},
Puzzle{
	"r1b2k1r/2q1b3/p3ppBp/2n3B1/1p6/2N4Q/PPP3PP/2KRR3 w - - 1 0",
	"1. Bxh6+ Rxh6 2. Qxh6+ Kg8 3. Qh7+ Kf8 4. Qf7#"
},
Puzzle{
	"r4n1k/ppBnN1p1/2p1p3/6Np/q2bP1b1/3B4/PPP3PP/R4Q1K w - - 1 0",
	"1. Qf7 Nf6 2. e5 Bxe5 3. Qg8+ Nxg8 4. Nf7#"
},
Puzzle{
	"r3k1r1/pp2bp1p/2ppb3/7P/3qP1n1/2N5/PPPQB1P1/R1B1KR2 b - - 0 1",
	"1... Bh4+ 2. g3 Bxg3+ 3. Rf2 Bxf2+ 4. Kd1 Ne3#"
},
Puzzle{
	"6k1/1p5p/p2p1q2/3Pb3/1Q2P3/3b1BpP/PPr3P1/KRN5 b - - 0 1",
	"1... Bxb2+ 2. Qxb2 Qxb2+ 3. Rxb2 Rxc1+ 4. Rb1 Rxb1# "
},
Puzzle{
	"5q2/p7/3R4/3Q2p1/5pk1/4p1P1/P6P/2r2NK1 w - - 1 0",
	"1. h3+ Kxh3 2. Qe6+ g4 3. Qh6+ Qxh6 4. Rxh6#"
},
Puzzle{
	"5q1k/p3R1rp/2pr2p1/1pN2bP1/3Q1P2/1B6/PP5P/2K5 w - - 1 0",
	"1. Qxg7+ Qxg7 2. Re8+ Qf8 3. Rxf8+ Kg7 4. Rg8# "
},
Puzzle{
	"6rk/2p2p1p/p2q1p1Q/2p1pP2/1nP1R3/1P5P/P5P1/2B3K1 w - - 1 0",
	"1. Qxh7+ Kxh7 2. Rh4+ Kg7 3. Bh6+ Kh7 4. Bf8#"
},
Puzzle{
	"4rbkr/3Q2pp/p7/1ppb4/8/1NP5/PP2qPPP/R1B2RK1 b - - 0 1",
	"1... Qxf1+ 2. Kxf1 Bc4+ 3. Qd3 Bxd3+ 4. Kg1 Re1# "
},
Puzzle{
	"6k1/5pb1/3p1n2/q1pP2Q1/2P4p/1r2R2P/5PPB/4R1K1 w - - 1 0",
	"1. Re8+ Nxe8 2. Rxe8+ Kh7 3. Qf5+ Kh6 4. Bf4#"
},
Puzzle{
	"r3rk2/6b1/q2pQBp1/1NpP4/1n2PP2/nP6/P3N1K1/R6R w - - 1 0",
	"1. Bxg7+ Kxg7 2. Rh7+ Kxh7 3. Qf7+ Kh8 4. Rh1#"
},
Puzzle{
	"5r1k/7b/4B3/6K1/3R1N2/8/8/8 w - - 1 0",
	"1. Ng6+ Bxg6 2. Kxg6 Rg8+ 3. Bxg8 Kxg8 4. Rd8#"
},
Puzzle{
	"2r3k1/pp4rp/1q1p2pQ/1N2p1PR/2nNP3/5P2/PPP5/2K4R w - - 1 0",
	"1. Qxg7+ Kxg7 2. Rxh7+ Kf8 3. Rh8+ Ke7 4. R1h7#"
},
Puzzle{
	"5n1k/rq4rp/p1bp1b2/2p1pP1Q/P1B1P2R/2N3R1/1P4PP/6K1 w - - 1 0",
	"1. Qxh7+ Nxh7 2. Rxh7+ Kxh7 3. Rh3+ Bh4 4. Rxh4# "
},
Puzzle{
	"r5k1/pbpn2pp/1p1pp1r1/5p2/1PPP3q/P3P1P1/3Q1P1P/R1BB1RK1 b - - 0 1",
	"1... Qxh2+ 2. Kxh2 Rh6+ 3. Bh5 Rxh5+ 4. Kg1 Rh1# "
},
Puzzle{
	"rnbqkb1r/np1p2pp/p1p1pp2/3PP3/2P2P2/P1NB4/1P4PP/R1BQK1NR w KQkq - 0 1",
	"1. Qh5+ g6 2. Bxg6+ hxg6 3. Qxg6+ Ke7 4. d6#"
},
Puzzle{
	"3q1r2/6k1/p2pQb2/4pR1p/4B3/2P3P1/P4PK1/8 w - - 1 0",
	"1. Rg5+ Kh6 2. Qf5 Qe8 3. Rg6+ Kh7 4. Qxh5#"
},
Puzzle{
	"rn2rk2/p1q1Nppp/1p4b1/2pP2Q1/2P5/6P1/PB3P1P/2R1R1K1 w - - 1 0",
	"1. Bxg7+ Kxg7 2. Nf5+ Kf8 3. Qh6+ Kg8 4. Rxe8# "
},
Puzzle{
	"3q4/1p3p1k/1P1prPp1/P1rNn1Qp/8/7R/6PP/3R2K1 w - - 1 0",
	"1. Rxh5+ Kg8 2. Rh8+ Kxh8 3. Qh6+ Kg8 4. Qg7# "
},
Puzzle{
	"2r2bk1/2qn1ppp/pn1p4/5N2/N3r3/1Q6/5PPP/BR3BK1 w - - 1 0",
	"1. Nh6+ gxh6 2. Qg3+ Rg4 3. Qxg4+ Bg7 4. Qxg7# "
},
Puzzle{
	"3r1kbR/1p1r2p1/2qp1n2/p3pPQ1/P1P1P3/BP6/2B5/6RK w - - 1 0",
	"1. Qxf6+ Rf7 2. Rxg7 Qxe4+ 3. Bxe4 Ke8 4. Qxf7# "
},
Puzzle{
	"rnb2rk1/ppp2qb1/6pQ/2pN1p2/8/1P3BP1/PB2PP1P/R4RK1 w - - 1 0",
	"1. Ne7+ Qxe7 2. Bd5+ Be6 3. Bxe6+ Rf7 4. Qxg7#"
},
Puzzle{
	"2rqr1k1/1p2bp1p/pn4p1/3p1bP1/3B3Q/2NR2R1/PPP1NP1P/1K6 w - - 1 0",
	"1. Qxh7+ Kxh7 2. Rh3+ Bxh3 3. Rxh3+ Kg8 4. Rh8# "
},
Puzzle{
	"4rk2/pb1Q1p2/6p1/3p2p1/2pP4/2q1PPK1/Pr4P1/1B2R2R w - - 1 0",
	"1. Rh8+ Kg7 2. Rh7+ Kxh7 3. Qxf7+ Kh8 4. Rh1#"
},
Puzzle{
	"r1b1r1k1/p1q3p1/1pp1pn1p/8/3PQ3/B1PB4/P5PP/R4RK1 w - - 1 0",
	"1. Rxf6 gxf6 2. Qg6+ Kh8 3. Qxe8+ Kg7 4. Qf8#"
},
Puzzle{
	"2r2k2/pb4bQ/1p1qr1pR/3p1pB1/3Pp3/2P5/PPB2PP1/1K5R w - - 1 0",
	"1. Qxg7+ Kxg7 2. Rh7+ Kg8 3. Rh8+ Kf7 4. R1h7#"
},
Puzzle{
	"8/4k2p/5p1b/q2bpP2/4B3/8/1PK4P/3QR3 b - - 0 1",
	"1... Qa4+ 2. Kb1 Ba2+ 3. Ka1 Bb3+ 4. Kb1 Qa2# "
},
Puzzle{
	"8/1p3pkp/6p1/6P1/5n2/p5q1/PP1Q2P1/3R2K1 w - - 1 0",
	"1. Qd4+ Kg8 2. Qd8+ Kg7 3. Qf6+ Kg8 4. Rd8# "
},
Puzzle{
	"r1r3k1/3NQppp/q3p3/8/8/P1B1P1P1/1P1R1PbP/3K4 b - - 0 1",
	"1... Qf1+ 2. Kc2 Be4+ 3. Rd3 Qxd3+ 4. Kb3 Qc4# "
},
Puzzle{
	"r3b3/1p3N1k/n4p2/p2PpP2/n7/6P1/1P1QB1P1/4K3 w - - 1 0",
	"1. Qh6+ Kg8 2. Qh8+ Kxf7 3. d6 Nb6 4. Bh5# "
},
Puzzle{
	"5Q2/8/6p1/2p4k/p1Bpq2P/6PK/P2b4/8 w - - 1 0",
	"1. Qh8+ Bh6 2. Qe5+ g5 3. Bf7+ Qg6 4. g4# "
},
Puzzle{
	"2Rr1qk1/5ppp/p2N4/P7/5Q2/8/1r4PP/5BK1 w - - 1 0",
	"1. Qxf7+ Qxf7 2. Rxd8+ Qf8 3. Bc4+ Kh8 4. Rxf8# "
},
Puzzle{
	"2qk1r2/Q3pr2/3p2pn/7p/5P2/4B2P/P1P3P1/1R4K1 w - - 1 0",
	"1. Bb6+ Ke8 2. Qa4+ Qd7 3. Qa8+ Qd8 4. Qxd8# "
},
Puzzle{
	"rnb3kb/pp5p/4p1pB/q1p2pN1/2r1PQ2/2P5/P4PPP/2R2RK1 w - - 1 0",
	"1. Qd6 Bg7 2. Qe7 Qc7 3. Qe8+ Bf8 4. Qxf8# "
},
Puzzle{
	"3Q4/4r1pp/b6k/6R1/8/1qBn1N2/1P4PP/6KR w - - 1 0",
	"1. Bxg7+ Rxg7 2. Qf6+ Rg6 3. Qf8+ Rg7 4. Qxg7# "
},
Puzzle{
	"2r5/1p5p/3p4/pP1P1R2/1n2B1k1/8/1P3KPP/8 w - - 1 0",
	"1. h3+ Kh4 2. g3+ Kxh3 3. Rh5+ Kg4 4. Bf3# "
},
Puzzle{
	"8/5r1p/R3pk2/2NR1np1/2P2r2/1P5K/P6P/8 b - - 0 1",
	"1... g4+ 2. Kg2 Ne3+ 3. Kg3 Rf3+ 4. Kh4 Rh3#"
},
Puzzle{
	"r1b1kr2/3q1p2/p1Q5/3p3p/8/3B4/PPP2PPP/R5K1 w q - 0 1",
	"1. Re1+ Kd8 2. Qb6+ Qc7 3. Qf6+ Qe7 4. Qxe7#"
},
Puzzle{
	"5r2/R4Nkp/1p4p1/2nR2N1/5p2/7P/6PK/1r6 w - - 1 0",
	"1. Nh6+ Nb7 2. Rxb7+ Rf7 3. Rxf7+ Kxh6 4. Rxh7#  "
},
Puzzle{
	"8/8/5K2/6r1/8/8/5Q1p/7k w - - 1 0",
	"1. Qf1+ Rg1 2. Qf3+ Rg2 3. Qe4 Kg1 4. Qe1# "
},
Puzzle{
	"6k1/4pp2/2q3pp/R1p1Pn2/2N2P2/1P4rP/1P3Q1K/8 b - - 0 1",
	"1... Rxh3+ 2. Kxh3 Qh1+ 3. Qh2 Qf3+ 4. Qg3 Qxg3# "
},
Puzzle{
	"4kb1Q/5p2/1p6/1K1N4/2P2P2/8/q7/8 w - - 1 0",
	"1. Qe5+ Kd7 2. Qc7+ Ke6 3. Qc8+ Kd6 4. Qc6# "
},
Puzzle{
	"q3r3/4b1pn/pNrp2kp/1p6/4P3/1Q2B3/PPP1B1PP/7K w - - 1 0",
	"1. Bh5+ Kxh5 2. Qf7+ g6 3. Qf3+ Kh4 4. Qh3#"
},
Puzzle{
	"r4r1k/1p3p1p/pp1p1p2/4qN1R/PP2P1n1/6Q1/5PPP/R5K1 w - - 1 0",
	"1. Rxh7+ Kxh7 2. Qh4+ Nh6 3. Qxh6+ Kg8 4. Qg7# "
},
Puzzle{
	"r3rn1k/4b1Rp/pp1p2pB/3Pp3/P2qB1Q1/8/2P3PP/5R1K w - - 1 0",
	"1. Rxf8+ Bxf8 2. Rxh7+ Kxh7 3. Qxg6+ Kh8 4. Qh7# "
},
Puzzle{
	"r1r3k1/1bq2pbR/p5p1/1pnpp1B1/3NP3/3B1P2/PPPQ4/1K5R w - - 1 0",
	"1. Bf6 Bxf6 2. Qh6 Ne6 3. Rh8+ Bxh8 4. Qxh8# "
},
Puzzle{
	"rk3q1r/pbp4p/1p3P2/2p1N3/3p2Q1/3P4/PPP3PP/R3R1K1 w - - 1 0",
	"1. Nd7+ Kc8 2. Nxf8+ Kb8 3. Re8+ Bc8 4. Qxc8#"
},
Puzzle{
	"3r3k/6pp/p3Qn2/P3N3/4q3/2P4P/5PP1/6K1 w - - 1 0",
	"1.Nf7+ Kg8 2.Nh6+ Kh8 3.Qg8+ Rxg8 4.Nf7# "
},
Puzzle{
	"4k3/2q2p2/4p3/3bP1Q1/p6R/r6P/6PK/5B2 w - - 1 0",
	"1. Bb5+ Bc6 2. Bxc6+ Qxc6 3. Rh8+ Kd7 4. Qd8#"
},
Puzzle{
	"3r1b2/3P1p2/p3rpkp/2q2N2/5Q1R/2P3BP/P5PK/8 w - - 1 0",
	"1. Rxh6+ Bxh6 2. Qxh6+ Kxf5 3. Qh5+ Ke4 4. Qf3# "
},
Puzzle{
	"r3kr2/ppq3bp/2np2p1/2pBp1B1/4P1Q1/2PP4/PP3PPP/R3K2R w KQq - 0 1",
	"1. Bxc6+ Kf7 2. Bd5+ Ke8 3. Qe6+ Qe7 4. Qxe7# "
},
Puzzle{
	"r2qr1k1/1p1n2pp/2b1p3/p2pP1b1/P2P1Np1/3BPR2/1PQB3P/5RK1 w - - 1 0",
	"1. Bxh7+ Kh8 2. Ng6+ Kxh7 3. Nf8+ Kg8 4. Qh7# "
},
Puzzle{
	"7r/pRpk4/2np2p1/5b2/2P4q/2b1BBN1/P4PP1/3Q1K2 b - - 0 1",
	"1... Bd3+ 2. Qxd3 Qh1+ 3. Nxh1 Rxh1+ 4. Ke2 Re1# "
},
Puzzle{
	"1r3rk1/5p1p/pp2b1p1/4n3/4PP2/1BP1B1Pq/P6P/R1QR2K1 b - - 0 1",
	"1... Nf3+ 2. Kf2 Qxh2+ 3. Kxf3 Bg4+ 4. Kxg4 Qh5# "
},
Puzzle{
	"2q2r1k/5Qp1/4p1P1/3p4/r6b/7R/5BPP/5RK1 w - - 1 0",
	"1. Bxh4 Rxf7 2. Be7+ Rh4 3. Rxh4+ Kg8 4. gxf7# "
},
Puzzle{
	"1r2k3/2pn1p2/p1Qb3p/7q/3PP3/2P1BN1b/PP1N1Pr1/RR5K b - - 0 1",
	"1... Rg1+ 2. Nxg1 Bf1+ 3. Nh3 Qxh3+ 4. Kg1 Qg2# "
},
Puzzle{
	"r1bqr3/4pkbp/2p1N2B/p2nP1Q1/2pP4/2N2P2/PP4P1/R3K2R w - - 1 0",
	"1. Qxg7+ Kxe6 2. Qg4+ Kf7 3. e6+ Bxe6 4. Qg7# "
},
Puzzle{
	"3R4/rr2pp1k/1p1p1np1/1B1Pq2p/1P2P3/5P2/3Q2PP/2R3K1 w - - 1 0",
	"1. Rh8+ Kxh8 2. Qh6+ Kg8 3. Rc8+ Ne8 4. Rxe8# "
},
Puzzle{
	"3Rr2k/pp4pb/2p4p/2P1n3/1P1Q3P/4r1q1/PB4B1/5RK1 b - - 0 1",
	"1... Nf3+ 2. Rxf3 Re1+ 3. Rf1 Rxf1+ 4. Kxf1 Qe1# "
},
Puzzle{
	"5r2/1pP1b1p1/pqn1k2p/4p3/QP2BP2/P3P1PK/3R4/3R4 w - - 1 0",
	"1. Qb3+ Kf6 2. Rd6+ Bxd6 3. Rxd6+ Ke7 4. Qe6# "
},
Puzzle{
	"1. b4+ axb4 2. axb4+ Kd5 3. c4+ bxc4 4. dxc4# ",
	""
},
Puzzle{
	"1r3r1k/6R1/1p2Qp1p/p1p4N/3pP3/3P1P2/PP2q2P/5R1K w - - 1 0",
	"1. Rh7+ Kxh7 2. Qe7+ Kg6 3. Qg7+ Kxh5 4. Qg4# "
},
Puzzle{
	"r1bq1rk1/4np1p/1p3RpB/p1Q5/2Bp4/3P4/PPP3PP/R5K1 w - - 1 0",
	"1. Qe5 Nf5 2. Rxf5 Qf6 3. Qxf6 Bxf5 4. Qg7#"
},
Puzzle{
	"2rr3k/1p1b1pq1/4pNp1/Pp2Q2p/3P4/7R/5PPP/4R1K1 w - - 1 0",
	"1. Rxh5+ Qh6 2. Rxh6+ Kg7 3. Rh7+ Kf8 4. Qd6# "
},
Puzzle{
	"3rnn2/p1r2pkp/1p2pN2/2p1P3/5Q1N/2P3P1/PP2qPK1/R6R w - - 1 0",
	"1. Qg5+ Ng6 2. Nf5+ exf5 3. Qh6+ Kh8 4. Qxh7# "
},
Puzzle{
	"r3r1n1/pp3pk1/2q2p1p/P2NP3/2p1QP2/8/1P5P/1B1R3K w - - 1 0",
	"1. Rg1+ Kf8 2. Rxg8+ Kxg8 3. Qh7+ Kf8 4. Qh8# "
},
Puzzle{
	"4Br1k/p5pp/1n6/8/3PQbq1/6P1/PP5P/RNB3K1 b - - 0 1",
	"1... Be3+ 2. Qxe3 Qd1+ 3. Qe1 Qxe1+ 4. Kg2 Qf1#"
},
Puzzle{
	"5rk1/pR4bp/6p1/6B1/5Q2/4P3/q2r1PPP/5RK1 w - - 1 0",
	"1. Rxg7+ Kxg7 2. Bh6+ Kh8 3. Qxf8+ Qg8 4. Bg7#"
},
Puzzle{
	"1r2r3/2p2pkp/p1b2Np1/4P3/2p4P/qP4N1/2P2QP1/5RK1 w - - 1 0",
	"1. Nfh5+ gxh5 2. Nxh5+ Kh6 3. Qf6+ Kxh5 4. Qg5#  "
},
Puzzle{
	"1b4rk/4R1pp/p1b4r/2PB4/Pp1Q4/6Pq/1P3P1P/4RNK1 w - - 1 0",
	"1. Qxg7+ Rxg7 2. Re8+ Bxe8 3. Rxe8+ Rg8 4. Rxg8#"
},
Puzzle{
	"4k2r/1R3R2/p3p1pp/4b3/1BnNr3/8/P1P5/5K2 w - - 1 0",
	"1. Rfe7+ Kd8 2. Nc6+ Kc8 3. Na7+ Kd8 4. Rbd7#  "
},
Puzzle{
	"1R2n1k1/r3pp1p/6p1/3P4/P1p2B2/6P1/5PKP/b7 w - - 1 0",
	"1. Bh6 Ra8 2. Rxa8 f5 3. Rxe8+ Kf7 4. Rf8#"
},
Puzzle{
	"r1b1k2N/pppp2pp/2n5/2b1p3/2B1n2q/2N3P1/PPPP1P1P/R1BQK2R b KQq - 0 1",
	"1... Bxf2+ 2. Kf1 Qh3+ 3. Ke2 Nd4+ 4. Kd3 Nc5# "
},
Puzzle{
	"2r4k/ppqbpQ1p/3p1bpB/8/8/1Nr2P2/PPP3P1/2KR3R w - - 1 0",
	"1. Bg7+ Bxg7 2. Rxh7+ Kxh7 3. Rh1+ Bh3 4. Rxh3#"
},
Puzzle{
	"r1brn3/p1q4p/p1p2P1k/2PpPPp1/P7/1Q2B2P/1P6/1K1R1R2 w - - 1 0",
	"1. Bxg5+ Kxg5 2. Qg3+ Kh5 3. Qg4+ Kh6 4. Qh4#"
},
Puzzle{
	"r1qr3k/3R2p1/p3Q3/1p2p1p1/3bN3/8/PP3PPP/5RK1 w - - 1 0",
	"1. Qh3+ Kg8 2. Nf6+ gxf6 3. Qh7+ Kf8 4. Qf7# "
},
Puzzle{
	"r7/5B2/3npkP1/7K/1P3p2/5P2/p7/R7 b - - 0 1",
	"1... Rh8+ 2. Kg4 Nf5 3. Rh1 Rxh1 4. Kxf4 Rh4# "
},
Puzzle{
	"2kr1b1r/pp1n1ppp/2n1p3/1N1pP3/QP1P4/P2q1N2/3B1PPP/2R1K2R w K - 0 1",
	"1. Rxc6+ bxc6 2. Qa6+ Kb8 3. Qxa7+ Kc8 4. Qc7#"
},
Puzzle{
	"r1b1k2r/pp2bpp1/1np1p2p/8/4BB2/3R1N2/qPP1QPPP/2K4R b kq - 0 1",
	"1... Qa1+ 2. Kd2 Nc4+ 3. Kc3 Qxb2+ 4. Kxc4 b5#"
},
Puzzle{
	"2r3k1/p4p2/1p2P1pQ/3bR2p/1q6/1B6/PP2RPr1/5K2 w - - 1 0",
	"1. exf7+ Bxf7 2. Re8+ Rxe8 3. Rxe8+ Qf8 4. Rxf8#"
},
Puzzle{
	"r1bkr3/1p3ppp/p1p5/4P3/2B1n3/2P1B3/P1P3PP/R4RK1 w - - 1 0",
	"1. Bb6+ Kd7 2. Rad1+ Nd6 3. Rxd6+ Ke7 4. Rxf7#"
},
Puzzle{
	"r4r1k/pppq1p1p/3p4/5p1Q/2B1Pp2/3P3P/PPn2P1K/R5R1 w - - 1 0",
	"1. Rg7 Kxg7 2. Qg5+ Kh8 3. Qf6+ Kg8 4. Rg1# "
},
Puzzle{
	"2kr1b1r/ppq5/1np1pp2/P3Pn2/1P3P2/2P2Qp1/6P1/RNB1RBK1 b - - 0 1",
	"1... Rh1+ 2. Kxh1 Qh7+ 3. Qh5 Qxh5+ 4. Kg1 Qh2#"
},
Puzzle{
	"2Q5/4ppbk/3p4/3P1NPp/4P3/5NB1/5PPK/rq6 w - - 1 0",
	"1. g6+ Kxg6 2. Nxe7+ Kh7 3. Qg8+ Kh6 4. Bf4# "
},
Puzzle{
	"5r1k/p1p1q1pp/1p1p4/8/2PPn3/B1P1P3/P1Q1P2p/1R5K b - - 0 1",
	"1... Nf2+ 2. Kxh2 Qh4+ 3. Kg2 Qh3+ 4. Kg1 Qh1# "
},
Puzzle{
	"2b5/3qr2k/5Q1p/P3B3/1PB1PPp1/4K1P1/8/8 w - - 1 0",
	"1. Bg8+ Kxg8 2. Qh8+ Kf7 3. Qg7+ Ke8 4. Qg8#"
},
Puzzle{
	"r1bq1bkr/6pp/p1p3P1/1p1p3Q/4P3/8/PPP3PP/RNB2RK1 w - - 1 0",
	"1. gxh7+ Rxh7 2. Qf7+ Kh8 3. Qxf8+ Qxf8 4. Rxf8# "
},
Puzzle{
	"rr4Rb/2pnqb1k/np1p1p1B/3PpP2/p1P1P2P/2N3R1/PP2BP2/1KQ5 w - - 1 0",
	"1. Bg7 Kxg8 2. Qh6 Bg6 3. Qxh8+ Kf7 4. fxg6# "
},
Puzzle{
	"r4b1r/pp1n2k1/1qp1p2p/3pP1pQ/1P6/2BP2N1/P4PPP/R4RK1 w - - 1 0",
	"1. Nf5+ exf5 2. e6+ Kh7 3. Qf7+ Bg7 4. Qxg7# "
},
Puzzle{
	"5k2/r3pp1p/6p1/q1pP3R/5B2/2b3PP/PQ3PK1/R7 w - - 1 0",
	"1. Qb8+ Qd8 2. Qxd8+ Kg7 3. Bh6+ Kf6 4. Qh8#"
},
Puzzle{
	"r3r1k1/pp3pb1/3pb1p1/q5B1/1n2N3/3B1N2/PPP2PPQ/2K4R w - - 1 0",
	"1. Qh7+ Kf8 2. Qxg7+ Kxg7 3. Bf6+ Kg8 4. Rh8# "
},
Puzzle{
	"4r1rk/pQ2P2p/P7/2pqb3/3p1p2/8/3B2PP/4RRK1 b - - 0 1",
	"1... Rxg2+ 2. Kh1 Rg1+ 3. Kxg1 Rg8+ 4. Kf2 Rg2# "
},
Puzzle{
	"r6r/pp2pk1p/1n3b2/5Q1N/8/3B4/q4PPP/3RR1K1 w - - 1 0",
	"1. Rxe7+ Kxe7 2. Qxf6+ Kd7 3. Bf5+ Ke8 4. Ng7# "
},
Puzzle{
	"3k4/1pp3b1/4b2p/1p3qp1/3Pn3/2P1RN2/r5P1/1Q2R1K1 b - - 0 1",
	"1... Rxg2+ 2. Kxg2 Qh3+ 3. Kg1 Qg3+ 4. Kh1 Nf2#"
},
Puzzle{
	"r4k2/1pp3q1/3p1NnQ/p3P3/2P3p1/8/PP6/2K4R w - - 1 0",
	"1. Qxg7+ Kxg7 2. Rh7+ Kf8 3. e6 Re8 4. Rf7# "
},
Puzzle{
	"8/6R1/1p1p4/1P1Np2k/2P1N2p/3P1p1q/1B2PP2/6K1 w - - 1 0",
	"1. Nf4+ exf4 2. Rg5+ Kh6 3. Bg7+ Kh7 4. Nf6#"
},
Puzzle{
	"4r1k1/1R4bp/pB2p1p1/P4p2/2r1pP1Q/2P4P/1q4P1/3R3K w - - 1 0",
	"1. Rxg7+ Kxg7 2. Rd7+ Kf8 3. Qf6+ Kg8 4. Qg7# "
},
Puzzle{
	"r2r4/1bp2pk1/p3pNp1/4P1P1/2p2Q2/2P5/qP3PP1/2K4R w - - 1 0",
	"1. Rh7+ Kf8 2. Nd7+ Rxd7 3. Rh8+ Ke7 4. Qf6#"
},
Puzzle{
	"r1kq1b1r/5ppp/p4n2/2pPR1B1/Q7/2P5/P4PPP/1R4K1 w - - 1 0",
	"1. Qc6+ Qc7 2. Re8+ Nxe8 3. Qxe8+ Qd8 4. Qxd8#"
},
Puzzle{
	"1Q6/5pp1/1B2p1k1/3pPn1p/1b1P4/2r3PN/2q2PKP/R7 b - - 0 1",
	"1... Ne3+ 2. Kh1 Qe4+ 3. f3 Qxf3+ 4. Kg1 Qg2# "
},
Puzzle{
	"8/pp2Q1p1/2p3kp/6q1/5n2/1B2R2P/PP1r1PP1/6K1 w - - 1 0",
	"1. Qe8+ Kh7 2. Bg8+ Kh8 3. Bf7+ Kh7 4. Qg8# "
},
Puzzle{
	"5r1k/1p4pp/p2N4/3Qp3/P2n1bP1/5P1q/1PP2R1P/4R2K w - - 1 0",
	"1. Nf7+ Kg8 2. Nh6+ Kh8 3. Qg8+ Rxg8 4. Nf7# "
},
Puzzle{
	"r1b1Q3/p1p3p1/1p3k1p/4N3/8/2P5/PP3PPP/2K4R w - - 1 0",
	"1. Qf7+ Kxe5 2. f4+ Kd6 3. Rd1+ Kc5 4. Qd5# "
},
Puzzle{
	"3q1rk1/ppr1pp1p/n5pQ/2pP4/4PP1N/PP1n2PB/7P/1R3RK1 w - - 1 0",
	"1. Nf5 gxf5 2. Bxf5 Re8 3. Qxh7+ Kf8 4. Qh8# "
},
Puzzle{
	"6k1/B2N1pp1/p6p/P3N1r1/4nb2/8/2R3B1/6K1 w - - 1 0",
	"1. Rc8+ Kh7 2. Nf8+ Kg8 3. Nfg6+ Kh7 4. Rh8# "
},
Puzzle{
	"4kr2/3rn2p/1P4p1/2p5/Q1B2P2/8/P2q2PP/4R1K1 w - - 1 0",
	"1. Qa8+ Rd8 2. Rxe7+ Kxe7 3. Qe4+ Kd6 4. Qe6# "
},
Puzzle{
	"2rkr3/3b1p1R/3R1P2/1p2Q1P1/pPq5/P1N5/1KP5/8 w - - 1 0",
	"1. Qxe8+ Kc7 2. Qxd7+ Kb8 3. Rb6+ Ka8 4. Qb7#"
},
Puzzle{
	"3q1r2/pb3pp1/1p6/3pP1Nk/2r2Q2/8/Pn3PP1/3RR1K1 w - - 1 0",
	"1. g4+ Kg6 2. Qf5+ Kh6 3. Nxf7+ Rxf7 4. Qh5#"
},
Puzzle{
	"8/8/2N5/8/8/p7/2K5/k7 w - - 1 0",
	"1. Nd4 Ka2 2. Ne2 Ka1 3. Nc1 a2 4. Nb3# "
},
Puzzle{
	"r3r1k1/1b6/p1np1ppQ/4n3/4P3/PNB4R/2P1BK1P/1q6 w - - 1 0",
	"1. Bc4+ d5 2. Bxd5+ Re6 3. Bxe6+ Nf7 4. Qh8# "
},
Puzzle{
	"1r1qrbk1/3b3p/p2p1pp1/3NnP2/3N4/1Q4BP/PP4P1/1R2R2K w - - 1 0",
	"1. Nxf6+ Kg7 2. Qg8+ Kxf6 3. Bh4+ g5 4. Bxg5# "
},
Puzzle{
	"5r1k/1q4bp/3pB1p1/2pPn1B1/1r6/1p5R/1P2PPQP/R5K1 w - - 1 0",
	"1. Rxh7+ Kxh7 2. Qh3+ Rh4 3. Qxh4+ Bh6 4. Qxh6# "
},
Puzzle{
	"3r1kr1/8/p2q2p1/1p2R3/1Q6/8/PPP5/1K4R1 w - - 1 0",
	"1. Rf1+ Kg7 2. Re7+ Qxe7 3. Qxe7+ Kh6 4. Rh1# "
},
Puzzle{
	"2R1R1nk/1p4rp/p1n5/3N2p1/1P6/2P5/P6P/2K5 w - - 1 0",
	"1. Nf6 Nce7 2. Rxe7 h5 3. Rxg8+ Rxg8 4. Rh7# "
},
Puzzle{
	"r1br2k1/4p1b1/pq2pn2/1p4N1/7Q/3B4/PPP3PP/R4R1K w - - 1 0",
	"1. Bh7+ Kf8 2. Qh5 Qg1+ 3. Kxg1 Bd7 4. Qf7# "
},
Puzzle{
	"R7/5pkp/3N2p1/2r3Pn/5r2/1P6/P1P5/2KR4 w - - 1 0",
	"1. Ne8+ Kf8 2. Nf6+ Rc8 3. Rxc8+ Ke7 4. Re8# "
},
Puzzle{
	"8/1R4pp/k2rQp2/2p2P2/p2q1P2/1n1r2P1/6BP/4R2K w - - 1 0",
	"1. Qe8 Qg1+ 2. Kxg1 Rb6 3. Ra7+ Kxa7 4. Qa8# "
},
Puzzle{
	"2b1k2r/3nb1pp/3npp2/B2pN1q1/Q2P4/4P3/PP3PPP/2R2RK1 w k - 0 1",
	"1. Rxc8+ Nxc8 2. Qxd7+ Kf8 3. Qxc8+ Bd8 4. Qxd8# "
},
Puzzle{
	"r2b2Q1/1bq5/pp1k2p1/2p1n1B1/P3P3/2N5/1PP3PP/5R1K w - - 1 0",
	"1. Rd1+ Nd3 2. Rxd3+ Ke5 3. Rd5+ Bxd5 4. Qxd5# "
},
Puzzle{
	"4Q3/1b5r/1p1kp3/5p1r/3p1nq1/P4NP1/1P3PB1/2R3K1 w - - 1 0",
	"1. Qf8+ Kd5 2. Qd8+ Rd7 3. Qxd7+ Ke4 4. Qxd4# "
},
Puzzle{
	"2rr2k1/1b3ppp/nq1p4/pB1P2Q1/PpP5/1N6/1P4PP/4RR1K w - - 1 0",
	"1. Rxf7 g6 2. Qf6 Qg1+ 3. Kxg1 Bxd5 4. Qg7#"
},
Puzzle{
	"r3r3/pppq1p1k/1bn2Bp1/3pPb2/1P1P4/P4N2/2BQ1PPP/R3R1K1 w - - 1 0",
	"1. Qg5 Bg4 2. Qh4+ Bh5 3. Qxh5+ Kg8 4. Qh8# "
},
Puzzle{
	"R6R/2kr4/1p3pb1/3prN2/6P1/2P2K2/1P6/8 w - - 1 0",
	"1. Ra7+ Kc6 2. Rc8+ Rc7 3. Rcxc7+ Kb5 4. Nd4# "
},
Puzzle{
	"7r/p3R3/BpkP4/2b1P1p1/8/1K2n1B1/P5P1/8 w - - 1 0",
	"1. Bb7+ Kb5 2. a4+ Ka5 3. Be1+ Bb4 4. Bxb4# "
},
Puzzle{
	"rn3rk1/1p3pB1/p4b2/q4P1p/6Q1/1B6/PPp2P1P/R1K3R1 w - - 1 0",
	"1. Bxf6+ hxg4 2. Rxg4+ Kh7 3. Rh4+ Kg8 4. Rh8# "
},
Puzzle{
	"r6r/p1qbB1kp/5p2/3Q2p1/8/P4N2/1P3PPP/4R1K1 w - - 1 0",
	"1. Bxf6+ Kf8 2. Bg7+ Kxg7 3. Re7+ Kf6 4. Qxg5# "
},
Puzzle{
	"r2q4/pp1rpQbk/3p2p1/2pPP2p/5P2/2N5/PPP2P2/2KR3R w - - 1 0",
	"1. Rxh5+ gxh5 2. Rh1 Kh8 3. Rxh5+ Bh6 4. Rxh6# "
},
Puzzle{
	"4qk2/6p1/p7/1p1Qp3/r1P2b2/1K5P/1P6/4RR2 w - - 1 0",
	"1. Rxf4+ exf4 2. Qf5+ Qf7 3. Qc8+ Qe8 4. Qxe8# "
},
Puzzle{
	"r1b2rk1/p1qnbp1p/2p3p1/2pp3Q/4pP2/1P1BP1R1/PBPP2PP/RN4K1 w - - 1 0",
	"1. Qxh7+ Kxh7 2. Rh3+ Bh4 3. Rxh4+ Kg8 4. Rh8#"
},
Puzzle{
	"qr3b1r/Q5pp/3p4/1kp5/2Nn1B2/Pp6/1P3PPP/2R1R1K1 w - - 1 0",
	"1. a4+ Kc6 2. Na5+ Kd5 3. Qf7+ Ne6 4. Rcd1# "
},
Puzzle{
	"rnb2r1k/pp2q2p/2p2R2/8/2Bp3Q/8/PPP3PP/RN4K1 w - - 1 0",
	"1. Rxf8+ Qxf8 2. Qxd4+ Qg7 3. Qd8+ Qg8 4. Qxg8#"
},
Puzzle{
	"8/8/p6p/1p3Kpk/1P2P3/P1b3P1/2N4P/8 w - - 1 0",
	"1. Ne3 Be1 2. Ng2 Bxg3 3. hxg3 g4 4. Nf4# "
},
Puzzle{
	"5rk1/3p1p1p/p4Qq1/1p1P2R1/7N/n6P/2r3PK/8 w - - 1 0",
	"1. Nf5 Rxg2+ 2. Kxg2 Re8 3. Rxg6+ hxg6 4. Qg7# "
},
Puzzle{
	"2b3k1/r3q2p/4p1pB/p4r2/4N3/P1Q5/1P4PP/2R2R1K w - - 1 0",
	"1. Qh8+ Kxh8 2. Rxc8+ Qf8 3. Rxf8+ Rxf8 4. Rxf8#"
},
Puzzle{
	"6rk/6pp/2p2p2/2B2P1q/1P2Pb2/1Q5P/2P2P2/3R3K w - - 1 0",
	"1. Qxg8+ Kxg8 2. Rd8+ Qe8 3. Rxe8+ Kf7 4. Rf8# "
},
Puzzle{
	"7r/p3pk2/1p6/1bp3K1/4BnP1/P1PP4/2n5/1R1R4 b - - 0 1",
	"1... Nh3+ 2. Kf5 Ne3+ 3. Ke5 Nxg4+ 4. Kf5 Bd7# "
},
Puzzle{
	"3R4/Q4p1k/2q2Pp1/1p5p/1Pr2b2/P3p3/1B5P/6K1 b - - 0 1",
	"1... Bxh2+ 2. Kxh2 Rh4+ 3. Kg3 Rg4+ 4. Kh2 Qg2# "
},
Puzzle{
	"2q4k/5pNP/p2p1BpP/4p3/1p2b3/1P6/P1r2R2/1K4Q1 w - - 1 0",
	"1. Ne6+ Kxh7 2. Ng5+ Kxh6 3. Qh2+ Qh3 4. Qxh3# "
},
Puzzle{
	"1r6/1p3K1k/p3N3/P6n/6RP/2P5/8/8 w - - 1 0",
	"1. Rg6 Nf6 2. Ng5+ Kh8 3. Rh6+ Nh7 4. Rxh7# "
},
Puzzle{
	"3r2k1/3N3p/4p1pQ/3p1p2/3P4/6BP/q4PPK/8 w - - 1 0",
	"1. Nf6+ Kf7 2. Qxh7+ Kxf6 3. Be5+ Kg5 4. f4# "
},
Puzzle{
	"r1b2k2/1p4pp/p4N1r/4Pp2/P3pP1q/4P2P/1P2Q2K/3R2R1 w - - 1 0",
	"1. Rd8+ Kf7 2. Qc4+ Be6 3. Qc7+ Bd7 4. Qxd7# "
},
Puzzle{
	"8/5p1k/4r1p1/2PP1p2/1Q6/1p3bbP/1B2pqP1/R5RK b - - 0 1",
	"1... Bxg2+ 2. Rxg2 Qf1+ 3. Rxf1 exf1=Q+ 4. Rg1 Qxh3# "
},
Puzzle{
	"r4r1k/1bpq1p1n/p1np4/1p1Bb1BQ/P7/6R1/1P3PPP/1N2R1K1 w - - 1 0",
	"1. Bf6+ Bxf6 2. Be4 Qf5 3. Bxf5 Bxb2 4. Qxh7# "
},
Puzzle{
	"rn3rk1/2qp2pp/p3P3/1p1b4/3b4/3B4/PPP1Q1PP/R1B2R1K w - - 1 0",
	"1. Bxh7+ Kxh7 2. Qh5+ Kg8 3. Rxf8+ Kxf8 4. Qf7#"
},
Puzzle{
	"6k1/6pp/1q6/4pp2/P5n1/1P6/1P3BPr/R4QK1 b - - 0 1",
	"1... Rh1+ 2. Kxh1 Qh6+ 3. Bh4 Qxh4+ 4. Kg1 Qh2# "
},
Puzzle{
	"6k1/1p2q2p/p3P1pB/8/1P2p3/2Qr2P1/P4P1P/2R3K1 w - - 1 0",
	"1. Qg7+ Qxg7 2. Rc8+ Rd8 3. Rxd8+ Qf8 4. Rxf8# "
},
Puzzle{
	"rk1r4/p3RR2/1p3Q2/3q1p2/2p2P2/7P/2P3P1/7K w - - 1 0",
	"1. Rb7+ Qxb7 2. Qxd8+ Qc8 3. Qd6+ Qc7 4. Qxc7# "
},
Puzzle{
	"8/R5p1/1R4p1/6k1/5p2/3r4/P3K3/3r4 b - - 0 1",
	"1... R3d2+ 2. Kf3 Rf1+ 3. Ke4 Re1+ 4. Kf3 Re3# "
},
Puzzle{
	"8/4k3/P4RR1/2b1r3/3n2Pp/8/5KP1/8 b - - 0 1",
	"1... Nc2+ 2. Kf3 Ne1+ 3. Kf4 Nd3+ 4. Kf3 Re3# "
},
Puzzle{
	"r3n1k1/pb5p/4N1p1/2pr4/q7/3B3P/1P1Q1PP1/2B1R1K1 w - - 1 0",
	"1. Qh6 Qf4 2. Bxf4 Rf5 3. Bxf5 gxf5 4. Qf8# "
},
Puzzle{
	"r1bq1r1k/pp1nb1p1/2p1ppB1/3pP3/2PP4/2P5/P1QN1PPP/R1B1K2R w KQ - 0 1",
	"1. Qd1 Kg8 2. Qh5 Re8 3. Qh7+ Kf8 4. Qh8#"
},
Puzzle{
	"3r2k1/1p3p1p/p1n2qp1/2B5/1P2Q2P/6P1/B2bRP2/6K1 w - - 1 0",
	"1. Qe8+ Rxe8 2. Rxe8+ Kg7 3. Bf8+ Kg8 4. Bh6# "
},
Puzzle{
	"1r3r2/1p5R/p1n2pp1/1n1B1Pk1/8/8/P1P2BPP/2K1R3 w - - 1 0",
	"1. Bh4+ Kxf5 2. Be6+ Kf4 3. Bg3+ Kg5 4. h4#"
},
Puzzle{
	"1. b6+ Ka6 2. Qd3+ Qc4 3. Qxc4+ Kxb6 4. Qb5# ",
	""
},
Puzzle{
	"8/2B3R1/2p1pkp1/1r2N3/1p6/7P/2r3PK/8 w - - 1 0",
	"1. Rf7+ Kg5 2. Bd8+ Kh6 3. Ng4+ Kh5 4. Rh7# "
},
Puzzle{
	"r2r4/1p1bn2p/pn2ppkB/5p2/4PQN1/6P1/PPq2PBP/R2R2K1 w - - 1 0",
	"1. Ne5+ fxe5 2. Qg5+ Kf7 3. Qg7+ Ke8 4. Qf8# "
},
Puzzle{
	"6k1/6pp/pp1p3q/3P4/P1Q2b2/1NN1r2b/1PP4P/6RK b - - 0 1",
	"1... Bg2+ 2. Rxg2 Re1+ 3. Qf1 Rxf1+ 4. Rg1 Qxh2#"
},
Puzzle{
	"3r1rk1/1q2b1n1/p1b1pRpQ/1p2P3/3BN3/P1PB4/1P4PP/4R2K w - - 1 0",
	"1. Ng5 Bxg2+ 2. Kg1 Rf7 3. Qh7+ Kf8 4. Qh8# "
},
Puzzle{
	"r2qr3/pbpnb1kp/1p2Q1p1/3p4/3P4/2P3NP/PPBB2P1/R4RK1 w - - 1 0",
	"1. Rf7+ Kh8 2. Rxh7+ Kxh7 3. Qxg6+ Kh8 4. Qh7# "
},
Puzzle{
	"r1b1qr2/pp2n1k1/3pp1pR/2p2pQ1/4PN2/2NP2P1/PP1K1PB1/n7 w - - 1 0",
	"1. Nh5+ Kg8 2. Rh8+ Kxh8 3. Qh6+ Kg8 4. Qg7#"
},
Puzzle{
	"r1qb1rk1/3R1pp1/p1nR2p1/1p2p2N/6Q1/2P1B3/PP3PPP/6K1 w - - 1 0",
	"1. Rxg6 fxg6 2. Rxg7+ Kh8 3. Qxg6 Qf5 4. Rh7#"
},
Puzzle{
	"r4r1k/pp1b2pn/8/3pR3/5N2/3Q4/Pq3PPP/5RK1 w - - 1 0",
	"1. Ng6+ Kg8 2. Ne7+ Kh8 3. Qxh7+ Kxh7 4. Rh5#  "
},
Puzzle{
	"1q1r1k2/1b2Rpp1/p1pQ3p/PpPp4/3P1NP1/1P3P1P/6K1/8 w - - 1 0",
	"1. Rxf7+ Kg8 2. Qg6 Qe5 3. dxe5 Kh8 4. Qxg7# "
},
Puzzle{
	"8/QrkbR3/3p3p/2pP4/1P3N2/6P1/6pK/2q5 w - - 1 0",
	"1. Ne6+ Kc8 2. Qa8+ Rb8 3. Qc6+ Bxc6 4. Rc7# "
},
Puzzle{
	"k2n1q1r/p1pB2p1/P4pP1/1Qp1p3/8/2P1BbN1/P7/2KR4 w - - 1 0",
	"1. Bc6+ Bxc6 2. Rxd8+ Qxd8 3. Qxc6+ Kb8 4. Qb7#  "
},
Puzzle{
	"3k4/R7/5N2/1p2n3/6p1/P1N2bP1/1r6/5K2 b - - 0 1",
	"1... Bg2+ 2. Ke1 Nd3+ 3. Kd1 Bf3+ 4. Ne2 Bxe2# "
},
Puzzle{
	"4rqk1/1bp2r1p/1p1p2pQ/3P1p2/P1P5/2B3RP/2B3P1/6K1 w - - 1 0",
	"1. Rxg6+ Qg7 2. Rxg7+ Kf8 3. Rxf7+ Kxf7 4. Qg7# "
},
Puzzle{
	"7k/3qbR1n/r5p1/3Bp1P1/1p1pP1r1/3P2Q1/1P5K/2R5 w - - 1 0",
	"1. Rxh7+ Kxh7 2. Qh3+ Rh4 3. Qxh4+ Kg7 4. Qh6# "
},
Puzzle{
	"8/6pk/2qrQ3/5P1p/5PNK/2n5/7P/4R3 w - - 1 0",
	"1. Nf6+ gxf6 2. Qf7+ Kh8 3. Qf8+ Kh7 4. Re7# "
},
Puzzle{
	"8/6k1/6p1/4p1K1/pPp1P1PP/3n1P2/6r1/R7 b - - 0 1",
	"1... Nf4 2. h5 Ne6+ 3. Kh4 g5+ 4. Kh3 Nf4# "
},
Puzzle{
	"6k1/1p3pp1/p1b1p2p/q3r1b1/P7/1P5P/1NQ1RPP1/1B4K1 b - - 0 1",
	"1... Qe1+ 2. Rxe1 Rxe1+ 3. Kh2 Bf4+ 4. g3 Rh1# "
},
Puzzle{
	"2rk2r1/3b3R/n3pRB1/p2pP1P1/3N4/1Pp5/P1K4P/8 w - - 1 0",
	"1. Rxd7+ Kxd7 2. Rf7+ Ke8 3. Rg7+ Kf8 4. Nxe6# "
},
Puzzle{
	"8/pp3pk1/2b2b2/8/2Q2P1r/2P1q2B/PP4PK/5R2 b - - 0 1",
	"1... Rxh3+ 2. gxh3 Qd2+ 3. Qe2 Qxe2+ 4. Kg1 Qg2#"
},
Puzzle{
	"k2r4/pp3p2/2p5/Q3p2p/4Kp1P/5R2/PP4q1/7R b - - 0 1",
	"1... Rd4+ 2. Kxe5 Qg7+ 3. Kf5 Qg6+ 4. Ke5 Re4# "
},
Puzzle{
	"3r2r1/4q1Bp/4k3/nBP2p1Q/P3p2P/4P1R1/8/4K3 w - - 1 0",
	"1. Rg6+ hxg6 2. Qxg6+ Qf6 3. Qxf6+ Kd5 4. Qxf5#"
},
Puzzle{
	"3r4/1p6/2p4p/5k2/p1P1n2P/3NK1nN/P1r5/1R2R3 b - - 0 1",
	"1... Rxd3+ 2. Kxd3 Rc3+ 3. Kd4 c5+ 4. Kd5 Rd3# "
},
Puzzle{
	"6k1/1p5p/1p2bp2/1Pnp1N2/1r6/3nBB2/1P4PP/R5K1 w - - 1 0",
	"1. Ra8+ Bc8 2. Bxd5+ Ne6 3. Bxe6+ Kf8 4. Rxc8# "
},
Puzzle{
	"4r2R/3q1kbR/1p4p1/p1pP1pP1/P1P2P2/K5Q1/1P2p3/8 w - - 1 0",
	"1. Rxg7+ Kxg7 2. Qc3+ Re5 3. Qxe5+ Kf7 4. Qf6# "
},
Puzzle{
	"2R2bk1/r4ppp/3pp3/1B2n1P1/3QP2P/5P2/1PK5/7q w - - 1 0",
	"1. Rxf8+ Kxf8 2. Qxd6+ Re7 3. Qb8+ Re8 4. Qxe8# "
},
Puzzle{
	"1rbq1rk1/p3npbp/2npp1PB/2p5/1p2P3/2NP2P1/PPPQ1PB1/R3K1NR w KQ - 0 1",
	"1. gxh7+ Kh8 2. Bxg7+ Kxg7 3. Qh6+ Kh8 4. Qf6#"
},
Puzzle{
	"6r1/3p2qk/4P3/1R5p/3b1prP/3P2B1/2P1QP2/6RK b - - 0 1",
	"1... Rxh4+ 2. Kg2 Qxg3+ 3. fxg3 Rxg3+ 4. Kf1 Rxg1#"
},
Puzzle{
	"5k1r/3b4/3p1p2/p4Pqp/1pB5/1P4r1/P1P5/1K1RR2Q w - - 1 0",
	"1. Qa8+ Bc8 2. Qxc8+ Kg7 3. Re7+ Kh6 4. Qxh8#"
},
Puzzle{
	"r3rk2/p3bp2/2p1qB2/1p1nP1RP/3P4/2PQ4/P5P1/5RK1 w - - 1 0",
	"1. Rg8+ Kxg8 2. Qg3+ Qg4 3. Qxg4+ Kh7 4. Qg7# "
},
Puzzle{
	"3R4/1p6/p1b1Q2p/6pk/1P6/P6P/1q4PK/8 w - - 1 0",
	"1. Qf7+ Kh4 2. Rd4+ Be4 3. Rxe4+ g4 4. Rxg4# "
},
Puzzle{
	"1R3nk1/5pp1/3N2b1/4p1n1/2BqP1Q1/8/8/7K w - - 1 0",
	"1. Rxf8+ Kxf8 2. Qc8+ Ke7 3. Qc7+ Kf8 4. Qd8# "
},
Puzzle{
	"2rqnk2/pp2p1b1/3pbpQR/4P1p1/2r3P1/1NN1BP2/PPP5/2K4R w - - 1 0",
	"1. Rh8+ Bg8 2. Rxg8+ Kxg8 3. e6 Nc7 4. Qf7# "
},
Puzzle{
	"1k2r3/7p/1p6/2p1r1nP/p1Pp1Np1/3K2P1/PPR2P2/2R5 b - - 0 1",
	"1... Re3+ 2. fxe3 Rxe3+ 3. Kd2 Nf3+ 4. Kd1 Re1# "
},
Puzzle{
	"2kr3r/R4Q2/1pq1n3/7p/3R1B1P/2p3P1/2P2P2/6K1 w - - 1 0",
	"1. Ra8+ Qxa8 2. Rc4+ Qc6 3. Rxc6+ Nc7 4. Qxc7# "
},
Puzzle{
	"2r2n1k/2q3pp/p2p1b2/2nB1P2/1p1N4/8/PPP4Q/2K3RR w - - 1 0",
	"1. Qxh7+ Nxh7 2. Rxh7+ Kxh7 3. Rh1+ Bh4 4. Rxh4# "
},
Puzzle{
	"7r/pp4Q1/1qp2p1r/5k2/2P4P/1PB5/P4PP1/4R1K1 w - - 1 0",
	"1. Re5+ fxe5 2. Qxe5+ Kg6 3. Qf6+ Kh5 4. Qg5# "
},
Puzzle{
	"8/2Q1R1bk/3r3p/p2N1p1P/P2P4/1p3Pq1/1P4P1/1K6 w - - 1 0",
	"1. Nf6+ Rxf6 2. Qxg3 Rf7 3. Rxf7 Kh8 4. Qxg7#"
},
Puzzle{
	"6k1/6p1/p5p1/3pB3/1p1b4/2r1q1PP/P4R1K/5Q2 w - - 1 0",
	"1. Rf8+ Kh7 2. Rh8+ Kxh8 3. Qf8+ Kh7 4. Qxg7# "
},
Puzzle{
	"2rq1rk1/pp4p1/2pb1pN1/n2p3Q/3P4/2N1B3/PPP2PP1/2K4R w - - 1 0",
	"1. Nh8 Nb3+ 2. Kd1 Bh2 3. Rxh2 Nxd4 4. Qh7#"
},
Puzzle{
	"4r1k1/3r1p1p/bqp1n3/p2p1NP1/Pn1Q1b2/7P/1PP3B1/R2NR2K w - - 1 0",
	"1. Rxe6 fxe6 2. Nh6+ Kf8 3. Qf6+ Rf7 4. Qxf7# "
},
Puzzle{
	"4r3/2RN4/p1r5/1k1p4/5Bp1/p2P4/1P4PK/8 w - - 1 0",
	"1. Rb7+ Ka4 2. b3+ Ka5 3. Bd2+ Rc3 4. Bxc3# "
},
Puzzle{
	"4rk1r/p2b1pp1/1q5p/3pR1n1/3N1p2/1P1Q1P2/PBP3PK/4R3 w - - 1 0",
	"1. Rxe8+ Bxe8 2. Ba3+ Qd6 3. Bxd6+ Kg8 4. Rxe8# "
},
Puzzle{
	"2b1rqk1/r1p2pp1/pp4n1/3Np1Q1/4P2P/1BP5/PP3P2/2KR2R1 w - - 1 0",
	"1. Nf6+ gxf6 2. Qxg6+ Kh8 3. Qh5+ Qh6+ 4. Qxh6# "
},
Puzzle{
	"8/5r2/3R4/3Pp1p1/p2pPk1p/P2PbP2/1P2K2P/4B3 w - - 1 0",
	"1. Rg6 Bg1 2. Bxh4 Bxh2 3. Rxg5 Bg1 4. Rg4# "
},
Puzzle{
	"b4rk1/5Npp/p3B3/1p6/8/3R4/PP4nP/6K1 w - - 1 0",
	"1. Ne5+ Kh8 2. Ng6+ hxg6 3. Rh3+ Nh4 4. Rxh4# "
},
Puzzle{
	"1r3r1k/2R4p/q4ppP/3PpQ2/2RbP3/pP6/P2B2P1/1K6 w - - 1 0",
	"1. Rxh7+ Kxh7 2. Qd7+ Rf7 3. Qxf7+ Kh8 4. Qg7# "
},
Puzzle{
	"2r1k2r/1p2pp1p/1p2b1pQ/4B3/3n4/2qB4/P1P2PPP/2KRR3 b - - 0 1",
	"1... Qxc2+ 2. Bxc2 Rxc2+ 3. Kb1 Bxa2+ 4. Ka1 Nb3#"
},
Puzzle{
	"4q3/pb5p/1p2p2k/4N3/PP1QP3/2P2PP1/6K1/8 w - - 1 0",
	"1. Ng4+ Kh5 2. Qe5+ Kg6 3. Qf6+ Kh5 4. Qh6#"
},
Puzzle{
	"7k/1p1P1Qpq/p6p/5p1N/6N1/7P/PP1r1PPK/8 w - - 1 0",
	"1. Ngf6 gxf6 2. Qxf6+ Kg8 3. Qd8+ Kf7 4. Qe8# "
},
Puzzle{
	"1R6/rbr2p2/5Pkp/2pBP1p1/ppP3P1/5K1P/P1PR4/8 w - - 1 0",
	"1. Bxb7 Raxb7 2. Rg8+ Kh7 3. Rg7+ Kh8 4. Rd8# "
},
Puzzle{
	"r3r3/2qb1pkp/p2p2pN/1p1pn3/7Q/P3B3/1PP1B1PP/R6K w - - 1 0",
	"1. Nf5+ gxf5 2. Bh6+ Kg8 3. Qf6 Qxc2 4. Qg7# "
},
Puzzle{
	"1k6/5Q2/2Rr2pp/pqP5/1p6/7P/2P3PK/4r3 w - - 1 0",
	"1. Qc7+ Ka8 2. Qc8+ Qb8 3. Qa6+ Qa7 4. Rc8# "
},
Puzzle{
	"5r1k/4R3/6pP/r1pQPp2/5P2/2p1PN2/2q5/5K1R w - - 1 0",
	"1. Rh7+ Kxh7 2. Qd7+ Rf7 3. Qxf7+ Kh8 4. Qg7#"
},
Puzzle{
	"3n3k/1p3B2/p2p1P2/2rP1br1/5p2/2P5/PP6/2KR2R1 w - - 1 0",
	"1. Rh1+ Bh7 2. Rxh7+ Kxh7 3. Rh1+ Rh5 4. Rxh5# "
},
Puzzle{
	"2r1rk2/6b1/1q2ppP1/pp1PpQB1/8/PPP2BP1/6K1/7R w - - 1 0",
	"1. Qxf6+ Bxf6 2. Bxf6 Qf2+ 3. Kxf2 exd5 4. Rh8#  "
},
Puzzle{
	"8/8/8/k1KB4/5r2/4R3/8/8 w - - 1 0",
	"1. Be4 Rf5+ 2. Bxf5 Ka6 3. Re7 Ka5 4. Ra7# "
},
Puzzle{
	"r1b2rk1/5pb1/p1n1p3/4B3/4N2R/8/1PP1p1PP/5RK1 w - - 1 0",
	"1. Nf6+ Bxf6 2. Bxf6 exf1=Q+ 3. Kxf1 Re8 4. Rh8# "
},
Puzzle{
	"3r1nQ1/1b4p1/1p3k1p/p1q5/P2N4/5P2/6PP/1B2R2K w - - 1 0",
	"1. Re6+ Nxe6 2. Qxe6+ Kg5 3. h4+ Kf4 4. Ne2# "
},
Puzzle{
	"6k1/ppp1q1pp/4p3/P7/1P2P1n1/2P1b2P/5rP1/RN2QB1K b - - 0 1",
	"1... Qh4 2. Ra2 Qg3 3. hxg4 Rxf1+ 4. Qxf1 Qh4# "
},
Puzzle{
	"4r1k1/3N1ppp/3r4/8/1n3p1P/5P2/PP3K1P/RN5R b - - 0 1",
	"1... Nd3+ 2. Kf1 Re1+ 3. Kg2 Rg6+ 4. Kh3 Nf2#"
},
Puzzle{
	"8/1bn5/ppk4q/1p1pQ2B/5P2/P3R2P/1Pr5/3R3K w - - 1 0",
	"1. Be8+ Nxe8 2. Qxd5+ Kc7 3. Re7+ Kb8 4. Qxb7# "
},
Puzzle{
	"1r3k2/5p1p/1qbRp3/2r1Pp2/ppB4Q/1P6/P1P4P/1K1R4 w - - 1 0",
	"1. Qh6+ Ke7 2. Rxe6+ fxe6 3. Qxe6+ Kf8 4. Qf7#"
},
Puzzle{
	"5r1k/3q3p/p2B1npb/P2np3/4N3/2N2b2/5PPP/R3QRK1 b - - 0 1",
	"1... Qh3 2. gxh3 Nf4 3. Ng5 Bxg5 4. Bxf8 Nxh3#  "
},
Puzzle{
	"6k1/8/3PN1p1/3Pp3/6r1/5p2/3q3P/5Q1K b - - 0 1",
	"1... Qe2 2. Qxe2 fxe2 3. h3 e1=Q+ 4. Kh2 Qg1# "
},
Puzzle{
	"2r3k1/pb3ppp/8/qP2b3/8/1P6/1P1RQPPP/1K3B1R b - - 0 1",
	"1... Rc1+ 2. Kxc1 Qa1+ 3. Kc2 Qxb2+ 4. Kd3 Qc3#"
},
Puzzle{
	"r1b2RB1/pp4p1/q5kp/5p2/3Q1P2/6P1/1PPK3P/8 w - - 1 0",
	"1. Bf7+ Kh7 2. Rh8+ Kxh8 3. Qd8+ Kh7 4. Qg8#"
},
Puzzle{
	"r3k3/3b3R/1n1p1b1Q/1p1PpP1N/1P2P1P1/6K1/2B1q3/8 w - - 1 0",
	"1. Rh8+ Bxh8 2. Qxh8+ Kf7 3. Qf6+ Ke8 4. Ng7# "
},
Puzzle{
	"5k1r/6p1/1Qq2p1p/2r1p3/2B3P1/1P6/1PP5/2K2R2 w - - 1 0",
	"1. Qd8+ Qe8 2. Rxf6+ gxf6 3. Qxf6+ Qf7 4. Qxf7# "
},
Puzzle{
	"r1b2r2/4nn1k/1q2PQ1p/5p2/pp5R/5N2/5PPP/5RK1 w - - 1 0",
	"1. Ng5+ Kg8 2. exf7+ Rxf7 3. Qxf7+ Kh8 4. Qh7# "
},
Puzzle{
	"7r/1p3bk1/1Pp2p2/3p2p1/3P1nq1/1QPNR1P1/5P2/5BK1 b - - 0 1",
	"1... Qh5 2. Bg2 Qh2+ 3. Kf1 Qh1+ 4. Bxh1 Rxh1# "
},
Puzzle{
	"6r1/pp3p1k/4bQ1p/2p2P1N/2P5/1P5P/1P3P1q/3R1K2 w - - 1 0",
	"1. Qg7+ Rxg7 2. Nf6+ Kh8 3. Rd8+ Rg8 4. Rxg8#"
},
Puzzle{
	"r1bq1rk1/pp1nb1pp/5p2/6B1/3pQ3/3BPN2/PP3PPP/R4RK1 w - - 1 0",
	"1. Qxh7+ Kf7 2. Bc4+ Ke8 3. Qg6+ Rf7 4. Qxf7# "
},
Puzzle{
	"3k4/1R6/1P2PNp1/7p/2n4P/8/4rPP1/6K1 w - - 1 0",
	"1. e7+ Kc8 2. Rc7+ Kb8 3. Nd7+ Ka8 4. Ra7# "
},
Puzzle{
	"2r3k1/pp2Bp1p/6p1/1P2P3/P7/1q2bP1P/3Q2P1/3R3K w - - 1 0",
	"1. Qd8+ Rxd8 2. Rxd8+ Kg7 3. Bf8+ Kg8 4. Bh6# "
},
Puzzle{
	"1R1br1k1/pR5p/2p3pB/2p2P2/P1qp2Q1/2n4P/P5P1/6K1 w - - 1 0",
	"1. Rg7+ Kh8 2. Rxh7+ Kxh7 3. Qxg6+ Kh8 4. Qg7# "
},
Puzzle{
	"4kb1r/1R6/p2rp3/2Q1p1q1/4p3/3B4/P6P/4KR2 w - - 1 0",
	"1. Bb5+ axb5 2. Qxb5+ Kd8 3. Rb8+ Kc7 4. Qb7# "
},
Puzzle{
	"6k1/2R5/4p1pp/8/5PPK/P3Q2P/1q4r1/8 b - - 0 1",
	"1... Qf6+ 2. g5 hxg5+ 3. fxg5 Qh8+ 4. Rh7 Qxh7# "
},
Puzzle{
	"3qr1k1/1pp3rn/p2p1Qp1/3P1pP1/2P2P2/2P2BK1/P6R/7R w - - 1 0",
	"1. Qxg7+ Kxg7 2. Rxh7+ Kf8 3. Rh8+ Ke7 4. R1h7#"
},
Puzzle{
	"4rnrk/ppqn2p1/4p1Pp/2p5/2PP1P2/3N3R/PP1N2Q1/1K4R1 w - - 1 0",
	"1. Rxh6+ gxh6 2. g7+ Kh7 3. Qe4+ Ng6 4. Qxg6#"
},
Puzzle{
	"5rk1/pp2Rppp/nqp5/8/5Q2/6PB/PPP2P1P/6K1 w - - 1 0",
	"1. Qxf7+ Rxf7 2. Re8+ Rf8 3. Be6+ Kh8 4. Rxf8# "
},
Puzzle{
	"3rk3/1q4pp/3B1p2/3R4/1pQ5/1Pb5/P4PPP/6K1 w - - 1 0",
	"1. Re5+ Kd7 2. Qe6+ Kc6 3. Bb8+ Rd6 4. Qxd6# "
},
Puzzle{
	"8/3n2pp/2qBkp2/ppPpp1P1/1P2P3/1Q6/P4PP1/6K1 w - - 1 0",
	"1. Qh3+ Kf7 2. Qh5+ Kg8 3. Qe8+ Nf8 4. Qxf8#"
},
Puzzle{
	"r1b2r1k/p1n3b1/7p/5q2/2BpN1p1/P5P1/1P1Q1NP1/2K1R2R w - - 1 0",
	"1. Rxh6+ Bxh6 2. Qxh6+ Qh7 3. Qxf8+ Qg8 4. Qxg8#"
},
Puzzle{
	"r3rb2/2qnk2p/p1bp2pB/n3p1N1/P3P3/2P3N1/Q4PPP/1R2R1K1 w - - 1 0",
	"1. Qe6+ Kd8 2. Nf7+ Kc8 3. Qxe8+ Qd8 4. Qxd8# "
},
Puzzle{
	"2q5/p3p2k/3pP1p1/2rN2Pn/1p1Q4/7R/PPr5/1K5R w - - 1 0",
	"1. Rxh5+ gxh5 2. Rxh5+ Kg6 3. Rh6+ Kxg5 4. Qf4# "
},
Puzzle{
	"2q3k1/1b1Q2bp/p1n2pp1/1p6/4B3/5N2/1PP2PPP/4R1K1 w - - 1 0",
	"1. Bd5+ Kh8 2. Re8+ Bf8 3. Qf7 Qxe8 4. Qg8# "
},
Puzzle{
	"1Q6/1R3pk1/4p2p/p3n3/P3P2P/6PK/r5B1/3q4 b - - 0 1",
	"1... Qg4+ 2. Kh2 Nf3+ 3. Kh1 Qh3+ 4. Bxh3 Rh2# "
},
Puzzle{
	"r4r2/2qnbpkp/b3p3/2ppP1N1/p2P1Q2/P1P5/5PPP/nBBR2K1 w - - 1 0",
	"1. Nxe6+ fxe6 2. Qh6+ Kf7 3. Qh5+ Kg8 4. Qxh7# "
},
Puzzle{
	"5Q2/1p3p1N/2p3p1/5b1k/2P3n1/P4RP1/3q2rP/5R1K w - - 1 0",
	"1. Rxf5+ g5 2. Qxf7+ Kh6 3. Rf6+ Nxf6 4. Rxf6# "
},
Puzzle{
	"rn3rk1/pp3p2/2b1pnp1/4N3/3q4/P1NB3R/1P1Q1PPP/R5K1 w - - 1 0",
	"1. Qh6 Nh5 2. Rxh5 Qxf2+ 3. Kxf2 gxh5 4. Qh7# "
},
Puzzle{
	"r4rk1/1q2bp1p/5Rp1/pp1Pp3/4B2Q/P2R4/1PP3PP/7K w - - 1 0",
	"1. Rh3 h5 2. Qxh5 gxh5 3. Rg3+ Kh8 4. Rh6# "
},
Puzzle{
	"r1br1b2/4pPk1/1p1q3p/p2PR3/P1P2N2/1P1Q2P1/5PBK/4R3 w - - 1 0",
	"1. Re6 Qxe6 2. Rxe6 Bxe6 3. Qg6+ Kh8 4. Qg8# "
},
Puzzle{
	"6r1/1p1qp1rk/p2pR1p1/3P2Qp/7P/5P2/PPP5/1K4R1 w - - 1 0",
	"1. Rxg6 Rxg6 2. Qxh5+ Kg7 3. Qxg6+ Kf8 4. Qxg8# "
},
Puzzle{
	"5rk1/pp1qpR2/6Pp/3ppNbQ/2nP4/B1P5/P5PP/6K1 w - - 1 0",
	"1. Rg7+ Kh8 2. Qxh6+ Bxh6 3. Rh7+ Kg8 4. Nxh6# "
},
Puzzle{
	"4k3/1p2rn2/pP1p1Q2/3Pp3/4Pp2/5q2/1PR5/1KN3B1 w - - 1 0",
	"1. Rc8+ Nd8 2. Qg6+ Kf8 3. Rxd8+ Re8 4. Rxe8# "
},
Puzzle{
	"r1br4/1p2bpk1/p1nppn1p/5P2/4P2B/qNNB3R/P1PQ2PP/7K w - - 1 0",
	"1. Qxh6+ Kg8 2. Rg3+ Ng4 3. Rxg4+ Bg5 4. Rxg5# "
},
Puzzle{
	"3Q4/6kp/4q1p1/2pnN2P/1p3P2/1Pn3P1/6BK/8 w - - 1 0",
	"1. h6+ Kxh6 2. Qf8+ Kh5 3. Bf3+ Qg4 4. Bxg4# "
},
Puzzle{
	"3r3r/ppk2B2/2n1Q1pp/5p2/3p4/q5P1/5P1P/1RR3K1 w - - 1 0",
	"1. Rxb7+ Kxb7 2. Qxc6+ Kb8 3. Rb1+ Qb4 4. Rxb4# "
},
Puzzle{
	"r6r/1q1nbkp1/pn2p2p/1p1pP1P1/3P1N1P/1P1Q1P2/P2B1K2/R6R w - - 1 0",
	"1. Qg6+ Kg8 2. Qxe6+ Kf8 3. Ng6+ Ke8 4. Qxe7# "
},
Puzzle{
	"5r1k/r2b1p1p/p4Pp1/1p2R3/3qBQ2/P7/6PP/2R4K w - - 1 0",
	"1. Qh6 Qd1+ 2. Rxd1 Rg8 3. Rh5 gxh5 4. Qxh7# "
},
Puzzle{
	"5Q2/1R6/p5p1/3P3k/2p1rP1p/8/4p1PP/q4BK1 w - - 1 0",
	"1. Rh7+ Kg4 2. Rxh4+ Kxh4 3. Qh6+ Kg4 4. Qg5# "
},
Puzzle{
	"4r1k1/5q2/p5pQ/3b1pB1/2pP4/2P3P1/1P2R1PK/8 w - - 1 0",
	"1. Bf6 Qh7 2. Rxe8+ Kf7 3. Qxh7+ Kxe8 4. Qe7#"
},
Puzzle{
	"5rk1/1R4b1/3p4/1P1P4/4Pp2/3B1Pnb/PqRK1Q2/8 b - - 0 1",
	"1... Bc3+ 2. Kd1 Qb1+ 3. Rc1 Qxd3+ 4. Qd2 Qxd2#"
},
Puzzle{
	"2rq1n1Q/p1r2k2/2p1p1p1/1p1pP3/3P2p1/2N4R/PPP2P2/2K4R w - - 1 0",
	"1. Rh7+ Ke8 2. Qxf8+ Kxf8 3. Rh8+ Ke7 4. R1h7# "
},
Puzzle{
	"8/pp2k1r1/3Np2p/5p1P/8/2Q3P1/5P1K/1q6 w - - 1 0",
	"1. Qc7+ Kf6 2. Ne8+ Kg5 3. Qxg7+ Kxh5 4. Nf6#"
},
Puzzle{
	"2r1rk2/1b2b1p1/p1q2nP1/1p2Q3/4P3/P1N1B3/1PP1B2R/2K4R w - - 1 0",
	"1. Rf2 Kg8 2. Qh2 Nh5 3. Qxh5 Bh4 4. Qh7# "
},
Puzzle{
	"4r3/5kp1/1N1p4/2pR1q1p/8/pP3PP1/6K1/3Qr3 b - - 0 1",
	"1... R8e2+ 2. Qxe2 Rxe2+ 3. Kf1 Qxf3+ 4. Kg1 Qg2# "
},
Puzzle{
	"2R3nk/3r2b1/p2pr1Q1/4pN2/1P6/P6P/q7/B4RK1 w - - 1 0",
	"1. Rxg8+ Kxg8 2. Nh6+ Kh8 3. Rf8+ Bxf8 4. Qg8#"
},
Puzzle{
	"8/6pk/1R2p2p/1P1pPp2/3P1P1K/1r5P/5QP1/2q5 b - - 0 1",
	"1... g5+ 2. Kh5 Rxh3+ 3. gxh3 Qd1+ 4. Qe2 Qxe2#"
},
Puzzle{
	"6Q1/1q2N1n1/3p3k/3P3p/2P5/3bp1P1/1P4BP/6K1 w - - 1 0",
	"1. Qh8+ Bh7 2. Be4 Qxe7 3. Qxh7+ Kg5 4. Qg6#"
},
Puzzle{
	"2r4k/p4rRp/1p1R3B/5p1q/2Pn4/5p2/PP4QP/1B5K w - - 1 0",
	"1. Rg8+ Rxg8 2. Qxg8+ Kxg8 3. Rd8+ Rf8 4. Rxf8#"
},
Puzzle{
	"1r1r4/Rp2np2/3k4/3P3p/2Q2p2/2P4q/1P1N1P1P/6RK w - - 1 0",
	"1. Ne4+ Kd7 2. Nf6+ Kd6 3. Qxf4+ Kc5 4. Qb4#"
},
Puzzle{
	"r2B1bk1/1p5p/2p2p2/p1n5/4P1BP/P1Nb4/KPn3PN/3R3R b - - 0 1",
	"1... Nb4+ 2. axb4 axb4+ 3. Ba5 Rxa5+ 4. Na4 Rxa4#"
},
Puzzle{
	"6r1/Q4p2/4pq1k/3p2Nb/P4P1K/4P3/7P/2R5 b - - 0 1",
	"1... Rxg5 2. Qe7 Rg4+ 3. Kh3 Qxe7 4. Rc8 Qh4#"
},
Puzzle{
	"5rk1/p3br1p/8/2p3p1/N2pPB2/1P1P1qPb/P2Q3P/R3R1K1 b - - 0 1",
	"1... Rxf4 2. gxf4 Rxf4 3. Rac1 Rg4+ 4. Qg2 Qxg2#"
},
Puzzle{
	"3Q1b2/5pk1/p3rNpp/1p2P3/4NP2/nP6/P3q1PP/3R3K w - - 1 0",
	"1. Qxf8+ Kxf8 2. Rd8+ Re8 3. Rxe8+ Kg7 4. Rg8#"
},
Puzzle{
	"1r1q4/5k2/1p1p2p1/2p4p/pPP1B1N1/P3Q1P1/2r2P1P/6K1 w - - 1 0",
	"1. Bd5+ Kf8 2. Qf4+ Qf6 3. Qxf6+ Ke8 4. Bc6# "
},
Puzzle{
	"3R4/7R/1P2k3/3p1pr1/3B4/2P5/r5b1/5BK1 w - - 1 0",
	"1. Re8+ Kd6 2. Rh6+ Rg6 3. Rxg6+ Kd7 4. Bb5#"
},
Puzzle{
	"6k1/pp1n2p1/8/5q2/b1pPp2Q/P1Pr4/4RB2/RK6 b - - 0 1",
	"1... Qb5+ 2. Rb2 Rd1+ 3. Ka2 Bb3+ 4. Rxb3 Qxb3#"
},
Puzzle{
	"4Nr1k/1bp2p1p/1r4p1/3P4/1p1q1P1Q/4R3/P5PP/4R2K w - - 1 0",
	"1. Qh6 Kg8 2. Re5 Qxe5 3. Rxe5 Rxe8 4. Rxe8#"
},
Puzzle{
	"1r2r2k/1q1n1p1p/p1b1pp2/3pP3/1b5R/2N1BBQ1/1PP3PP/3R3K w - - 1 0",
	"1. Rxh7+ Kxh7 2. Rd4 Bf8 3. Rh4+ Bh6 4. Rxh6#"
}};
