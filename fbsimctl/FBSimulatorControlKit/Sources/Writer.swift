/**
 * Copyright (c) 2015-present, Facebook, Inc.
 * All rights reserved.
 *
 * This source code is licensed under the BSD-style license found in the
 * LICENSE file in the root directory of this source tree. An additional grant
 * of patent rights can be found in the PATENTS file in the same directory.
 */

import Foundation

/**
 A Protocol for writing Strings out.
 */
public protocol Writer {
  func write(string: String)
}

/**
 A Protocol for writing Strings out.
 */
public struct SuccessFailureWriter {
  let success: Writer
  let failure: Writer
}

/**
 Enum for defining the result of a translation.
 */
public enum ActionResult {
  case Success
  case Failure(String)

  func append(second: ActionResult) -> ActionResult {
    switch (self, second) {
    case (.Success, .Success):
      return .Success
    case (.Success, .Failure(let secondString)):
      return .Failure(secondString)
    case (.Failure(let firstString), .Success):
      return .Failure(firstString)
    case (.Failure(let firstString), .Failure(let secondString)):
      return .Failure("\(firstString)\n\(secondString)")
    }
  }
}

/**
 A Protocol for writing an ActionResult.
 */
public extension SuccessFailureWriter {
  func writeActionResult(actionResult: ActionResult) {
    switch actionResult {
    case .Failure(let string):
      self.failure.write(string)
    default:
      break
    }
  }
}
