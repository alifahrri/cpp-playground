## Non-Virtual Interface
from [1] :
> The essence of the non-virtual interface pattern is that you have private virtual functions, which are called by public non-virtual functions (the non-virtual interface).

### Result 
```
./cpp-exercise-06-demo-01
```
```
void BaseProcess::process() calling preprocess :
virtual void DummyProcess::preporcess() : doing preprocessing
void BaseProcess::process() doing work :
virtual void DummyProcess::work() : incrementing the counter
void BaseProcess::process() doing work :
virtual void DummyProcess::work() : incrementing the counter
void BaseProcess::process() doing work :
virtual void DummyProcess::work() : incrementing the counter
void BaseProcess::process() doing work :
virtual void DummyProcess::work() : incrementing the counter
void BaseProcess::process() doing work :
virtual void DummyProcess::work() : incrementing the counter
void BaseProcess::process() doing work :
virtual void DummyProcess::work() : incrementing the counter
void BaseProcess::process() doing work :
virtual void DummyProcess::work() : incrementing the counter
void BaseProcess::process() doing work :
virtual void DummyProcess::work() : incrementing the counter
void BaseProcess::process() doing work :
virtual void DummyProcess::work() : incrementing the counter
void BaseProcess::process() calling postprocess :
virtual void DummyProcess::postporcess() : done! see you
void BaseProcess::process() calling preprocess :
virtual void FakeProcess::preporcess() : doing preprocessing
void BaseProcess::process() doing work :
virtual void FakeProcess::work() : sleeping for 500ms
void BaseProcess::process() doing work :
virtual void FakeProcess::work() : sleeping for 500ms
void BaseProcess::process() doing work :
virtual void FakeProcess::work() : sleeping for 500ms
void BaseProcess::process() doing work :
virtual void FakeProcess::work() : sleeping for 500ms
void BaseProcess::process() doing work :
virtual void FakeProcess::work() : sleeping for 500ms
void BaseProcess::process() doing work :
virtual void FakeProcess::work() : sleeping for 500ms
void BaseProcess::process() calling postprocess :
virtual void FakeProcess::postporcess() : done! see you
```
### Reference
[1] https://stackoverflow.com/questions/6481260/non-virtual-interface-design-pattern-in-c-c