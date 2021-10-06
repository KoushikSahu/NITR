stimulus_situation(verbal, E) :- E = (papers) ; E = (manuals) ; E = (documents) ; E = (textbooks).
stimulus_situation(visual, E) :- E = (pictures) ; E = (illustrations) ; E =(photographs) ; E = (diagrams).
stimulus_situation('physical object', E) :- E = (machines) ; E = (buildings) ; E = (tools).
stimulus_situation(symbolic, E) :- E = (numbers) ; E = (formulas) ; E = ('computer programs').
stimulus_response(oral, J) :- J = (lecturing) ; J = (counselling) ; J = (advising).
stimulus_response('hands-on', J) :- J = (building) ; J = (repairing) ; J = (troubleshooting).
stimulus_response(documented, J) :- J = (writing) ; J = (typing) ; J = (drawing).
stimulus_response(analytical, J) :- J = (evaluating) ; J = (reasoning) ; J = (investigating).
medium(workshop, S, R, F) :- S = ('physical object'), R = ('hands-on'), F = (yes).
medium('lecture-tutorial',S,R,F) :- S = (symbolic), R = (analytical), F = (yes).
medium(videocassette, S, R, F) :- S = (visual), R = (documented), F = (no).
medium('lecture-tutorial', S, R, F) :- S = (visual), R = (oral), F = (yes).
medium('lecture-tutorial', S, R, F) :- S = (verbal), R = (analytical), F = (yes).
medium('role-play exercises', S, R, F) :- S = (verbal), R = (oral), F = (yes).

suggest(M) :- write('What is your environment? '), read(Environment), stimulus_situation(S,Environment), write('What is your job? '), read(Job), stimulus_response(R, Job), write('Do you want feedback? '), read(F), medium(M, S, R, F).

