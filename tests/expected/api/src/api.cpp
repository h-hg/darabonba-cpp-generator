// This file is auto-generated, don't edit it. Thanks.

#include <darabonba/api.hpp>
#include <boost/any.hpp>
#include <boost/throw_exception.hpp>
#include <darabonba/core.hpp>
#include <iostream>
#include <map>

using namespace std;

using namespace Darabonba_Api;

Darabonba_Api::Client::Client(){}
void Darabonba_Api::Client::hello() {
  shared_ptr<Darabonba::Request> request_ = make_shared<Darabonba::Request>();
  request_->method = "GET";
  request_->pathname = "/";
  request_->headers = {
    {"host", "www.test.com"}
  };
  shared_ptr<Darabonba::Request> _lastRequest = request_;
  shared_ptr<Darabonba::Response> response_ = make_shared<Darabonba::Response>(Darabonba::Core::doAction(request_));
  return;
}

void Darabonba_Api::Client::helloRuntime() {
  map<string, boost::any> runtime_ = map<string, boost::any>();
  shared_ptr<Darabonba::Request> _lastRequest;
  std::exception _lastException;
  int _now = 0;
  int _retryTimes = 0;
  while (Darabonba::Core::allowRetry(make_shared<boost::any>(runtime_["retry"]), make_shared<int>(_retryTimes), make_shared<int>(_now))) {
    if (_retryTimes > 0) {
      int _backoffTime = Darabonba::Core::getBackoffTime(make_shared<boost::any>(runtime_["backoff"]), make_shared<int>(_retryTimes));
      if (_backoffTime > 0) {
        Darabonba::Core::sleep(make_shared<int>(_backoffTime));
      }
    }
    _retryTimes = _retryTimes + 1;
    try {
      shared_ptr<Darabonba::Request> request_ = make_shared<Darabonba::Request>();
      request_->method = "GET";
      request_->pathname = "/";
      request_->headers = {
        {"host", "www.test.com"}
      };
      _lastRequest = request_;
      shared_ptr<Darabonba::Response> response_ = make_shared<Darabonba::Response>(Darabonba::Core::doAction(request_, runtime_));
      return;
    }
    catch (std::exception &e) {
      if (Darabonba::Core::isRetryable(e)) {
        _lastException = e;
        continue;
      }
      BOOST_THROW_EXCEPTION(e);
    }
  }
  BOOST_THROW_EXCEPTION(Darabonba::UnretryableError(_lastRequest, _lastException));
}

